//
// Created by 22343 on 2021/2/27.
//

#include "client.h"

#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <memory.h>
#include <unistd.h>
#include "client.h"
#include "common.h"
#include "config.h"

int handleUserRequest(struct Config config, int userSock) {
    int serverSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSock < 0) {
        return -1;
    }

    struct sockaddr_in remoteAddr;
    remoteAddr.sin_family = AF_INET;
    remoteAddr.sin_port = htons(config.serverPort);
    struct hostent *dstHost = gethostbyname(config.serverHost);  // gethostbyname()函数：通过域名获取IP地址
    remoteAddr.sin_addr.s_addr = *(in_addr_t *)dstHost->h_addr;

    if (retryConnect(serverSock, (struct sockaddr*)&remoteAddr, sizeof(remoteAddr)) < 0) {
        return -1;
    }

    if (fork() == 0) {
        printf("☑️ Try : Client <=> Server\n");
        forwardData(userSock, serverSock, 1); // 加密
        exit(0);
    }
    if (fork() == 0) {
        forwardData(serverSock, userSock, 1); // 解密
        printf("✅ Finish: Client <=> Server\n");
        exit(0);
    }

    return 0;
}

void clientLoop(struct Config config, int clientSock) {
//    printf("client loop...\n");
    struct sockaddr_in userAddr;//  sockaddr_in 结构  四个参数  sin_family sin_port sin_addr  sin_zero[8]
    socklen_t clientAddrLength = sizeof(userAddr); // socklen_t 数据类型，好像用于解决accept函数第三个参数跨平台问题,见 https://www.jianshu.com/p/51347fcf539c

    while (1) {

//        printf("wait for user...\n");
        int userSock = accept(clientSock, (struct sockaddr *)&userAddr, &clientAddrLength);// accept() 返回一个新的套接字来和客户端通信，addr 保存了客户端的IP地址和端口号，而 sock 是服务器端的套接字，大家注意区分。后面和客户端通信时，要使用这个新生成的套接字，而不是原来服务器端的套接字。
        if (userSock == -1) {
            continue;
        }
        if (fork() == 0) { //fork函数返回两个值，对于子进程，返回0; 父进程，返回子进程ID.
            close(clientSock);// 关闭 clientSock,不再监听本地
            handleUserRequest(config, userSock);
            exit(0);
        }
        close(userSock);
    }
}

void startClient(struct Config config) {
    printf("🔔 Start client...\n");
    int clientSock = createListeningSocket(config.localPort); //创建监听端口
    if (clientSock < 0) {
        printf("❗ Cannot create listening socket on port %d.\n", config.localPort);
        exit(clientSock);
    }

    clientLoop(config, clientSock);
}