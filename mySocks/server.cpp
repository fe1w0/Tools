//
// Created by 22343 on 2021/2/27.
//
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <memory.h>
#include <netdb.h>
#include <uv.h>
#include "server.h"
#include "common.h"
#include "socks5.h"
#include "string.h"


/**
 * 验证 USERNAME/PASSWORD
 * @param clientSock
 * @return
 */
int AuthSock5Connection(struct Config config,int clientSock){
//    printf("Auth sock5 connection.\n");
    char buffer[SOCK5_AUTHENTICATION_REQUEST_MAX_LENGTH];// 协议版本与认证方法数据包的长度为513

    ssize_t len = retryRecv(clientSock, buffer, SOCK5_BUILD_REQUEST_MAX_LENGTH);
    if (len  < 0) {
        return -1;
    }
    encryptData((uint8_t *)buffer, len);

    int ok = 0;
    struct Sock5AuthRequest request = Sock5AuthRequest_read((Byte *)buffer); //读取 socks package

    if( strcmp((char *) request.username ,config.username) == 0  && strcmp((char *) request.password ,config.password) == 0   && request.version == 0x01 ){
        ok = 1;
    }
    else{
        if(  strcmp((char *) request.username ,config.username) != 0  ){
            printf("❗ Error: username\n");
            printf("Request: %s\n",(char *) request.username);
            printf("config: %s\n",config.username);
        }
        if( strcmp((char *) request.password ,config.password) != 0 ){
            printf("❗ Error: password\n");
            printf("Request: %s\n",(char *) request.password);
            printf("config: %s\n",config.password);
        }
        if( request.version != 0x01){
            printf("❗ Error: Version\n");
        }
    }
    struct Sock5AuthResponse response;
    response.version = 0x01;
    response.Status = ok ? (Byte)0x00 : (Byte)0xFF;
    char *  responsechar  = Sock5AuthResponse_toString(response);
    encryptData((uint8_t *)responsechar,sizeof(responsechar));
    return (int)retrySend(clientSock,responsechar, 2);
}


int validateSock5Connection(struct Config config,int clientSock) {
    // 验证 客户端发送的 DateSource,具体数据格式见 https://www.quarkay.com/code/383/socks5-protocol-rfc-chinese-traslation
//    printf("validate sock5 connection.\n");
    char buffer[SOCK5_VALIDATE_REQUEST_MAX_LENGTH];// 协议版本与认证方法数据包的长度最大为257
    ssize_t len = retryRecv(clientSock, buffer, SOCK5_BUILD_REQUEST_MAX_LENGTH);
    if (len  < 0) {
        return -1;
    }
    encryptData((uint8_t *)buffer, len);

    struct Sock5ValidateRequest request = Sock5ValidateRequest_read((Byte *)buffer); //读取 socks package

    int ok = 1;

    ok &= request.version == 0x05;    // 验证客户端协议版本是否正确

    // 验证客户端是否支持无验证方式的请求
    int allowNoAuth = 0;
    int allowAuth =0;
    for (int i = 0; i < request.methodNum; i++) {
        if (request.methods[i] == 0x02 ){
            allowAuth = 1 ;
//            printf("Allowed Method: USERNAME/PASSWORD\n");
        }
        if (request.methods[i] == 0x00) {
            allowNoAuth = 1;
//            printf("Allowed Method: NoAuth\n");
        }
        //是否是 USERNAME/PASSWORD
    }
    struct Sock5ValidateResponse response;
    response.version = 0x05;
    if(ok && allowAuth){
        response.method = (Byte)0x02 ;
        char *  responsechar  = Sock5ValidateResponse_toString(response);
        encryptData((uint8_t *)responsechar,sizeof(responsechar));
        retrySend(clientSock,responsechar, 2);
        return (int)AuthSock5Connection(config,clientSock);
    }else{
        response.method = (ok && allowNoAuth) ? (Byte)0x00 : (Byte)0xFF;
        char *  responsechar  = Sock5ValidateResponse_toString(response);
        encryptData((uint8_t *)responsechar,sizeof(responsechar));
        return (int)retrySend(clientSock,responsechar, 2);
    }
}



int createSock5Connection(struct Config config, int clientSock) {
//    printf("Create sock5 connection.\n");
    char buffer[SOCK5_BUILD_REQUEST_MAX_LENGTH];
    ssize_t len = retryRecv(clientSock, buffer, SOCK5_BUILD_REQUEST_MAX_LENGTH);
    if (len  < 0) {
        return -1;
    }
    encryptData((uint8_t *)buffer, len);

    struct Sock5BuildRequest request = Sock5BuildRequest_read((Byte *)buffer);
    if (request.version < 0) {
        return -1;
    }
//    printf("Request's Version Correct\n");
    if (request.cmd != 0x01) {   // 目前支持CONNECT方式，后续扩展
        return -1;
    }
//    printf("Method: CONNECT\n");
    // 代理服务器创建到远程主机的连接
    int remoteSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (remoteSock < 0) {
        return -1;
    }
//    printf("CreateSock5Connection: Create remoteSock\n");
    struct sockaddr_in remoteAddr;
    remoteAddr.sin_family = AF_INET;
    remoteAddr.sin_port = htons(request.dstPort);

    if (request.atyp == 0x01) { // IPV4　X‘01’
        in_addr_t ip;
        memcpy(&ip, request.dstAddr, 4);
        char str[32];
//        printf("IPv4 Address: %s\n",inet_ntop(AF_INET,&ip,str, sizeof(str)));
        remoteAddr.sin_addr.s_addr = ip;
    } else if (request.atyp == 0x03) { // 域名　X‘03’
        struct hostent *dstHost = gethostbyname(Byte_arrayToStr(request.dstAddr, request.addrLength));// 域名 -> IP v4
        char str[32];
//        printf("IPv4 Address: %s\n",inet_ntop(dstHost->h_addrtype,dstHost->h_addr_list[0],str, sizeof(str)));
        remoteAddr.sin_addr.s_addr = *(in_addr_t *)dstHost->h_addr;
    } else {
        return -1;
    }
//    printf("remoteAddr.sin_addr: %s\n",inet_ntoa(remoteAddr.sin_addr));
    printf("☑️ Try: Server <=> Domain\n");
    if (retryConnect(remoteSock, (struct sockaddr*)&remoteAddr, sizeof(remoteAddr)) < 0) {
        printf("❗ Error: Server <=> Domain\n");
        return -1;
    }
    // 响应客户端
    printf("✅ Finish: Server <=> Domain\n");
//    printf("☑️Try To Response\n");
    struct Sock5BuildResponse response;
    response.version = 0x05;
    response.rep = 0x00;
    response.rsv = 0x00;
    response.atyp = 0x01;
    response.addrLength = 4;
    uint ip = (127U << 24) + 1;
    response.bndAddr = (Byte *)&ip;
    response.bndPort = (ushort)config.localPort;
    char* responseStr = Sock5BuildResponse_toString(response);
    encryptData((uint8_t *)responseStr,sizeof(responseStr));
    if (retrySend(clientSock, responseStr, Sock5BuildResponse_getLength(response)) < 0) {
        printf("❗ Error: Client -> Server\n");
        return -1;
    }
    printf("✅ Finish: Server <=> Client\n");
    return remoteSock;
}

void handleClientRequest(struct Config config, int clientSock) {
//    printf("handle client socket.\n");
    if (validateSock5Connection(config,clientSock) < 0) {
        return;
    }
    int remoteSock = createSock5Connection(config, clientSock);
    if (remoteSock < 0) {
        return;
    }

    if (fork() == 0) {
        forwardData(clientSock, remoteSock, 1);  //解密
        exit(0);
    }
    if (fork() == 0) {
        forwardData(remoteSock, clientSock, 1); //加密
        exit(0);
    }
}


void serverLoop(struct Config config, int serverSock) {
//    printf("server loop...\n");
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLength = sizeof(clientAddr);

    while (1) {
//        printf("wait for client...\n");
        int clientSock = accept(serverSock, (struct sockaddr*)&clientAddr, &clientAddrLength);
        if (clientSock == -1) {
            continue;
        }
//        printf("client sock: %d\n", clientSock);
        if (fork() == 0) {
            close(serverSock);
            handleClientRequest(config, clientSock);
            exit(0);
        }
        close(clientSock);
    }
}

void startServer(struct Config config) {
    printf("🔔 start server...\n");
    int serverSock = createListeningSocket(config.localPort);
    if (serverSock < 0) {
        printf("❗ Cannot create server socket.");
        exit(serverSock);
    }

    serverLoop(config, serverSock);
}
