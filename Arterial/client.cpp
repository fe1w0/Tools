//
// Created by 22343 on 2021/3/16.
//

#include "client.h"

char * getIPV4(char * domainName){
    WSADATA wsaData;
    WSAStartup( MAKEWORD(2, 2), &wsaData);
    struct hostent *host = gethostbyname(domainName);
    return inet_ntoa( *(struct in_addr*)host->h_addr_list[0] ) ;
}

void clientStart(Config config){
    //初始化DLL
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    //创建套接字
    SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    //向服务器发起请求
    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));  //每个字节都用0填充
    sockAddr.sin_family = PF_INET;

    char * serverHost = getIPV4(config.serverHost);
    sockAddr.sin_addr.s_addr = inet_addr(serverHost);

    sockAddr.sin_port = htons(config.port);

    printf("The client is created\n");
    connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
    //接收服务器传回的数据
    recvFile(config,sock);
    //关闭套接字
    closesocket(sock);
    //终止使用 DLL
    WSACleanup();
//    system("pause");
    return ;
}

void recvFile(Config  config,SOCKET sock){
    printf("%s file waiting to be received\n",config.fileName);

    //先输入文件名，看文件是否能创建成功
    char * fileName = config.fileName;
    FILE *fp = fopen(fileName, "wb");  //以二进制方式打开（创建）文件
    if(fp == NULL){
        printf("Cannot open file, press any key to exit!\n");
        system("pause");
        exit(0);
    }

    char buffer[BUF_SIZE] = {0};  //文件缓冲区
    int nCount;
    while( (nCount = recv(sock, buffer, BUF_SIZE, 0)) > 0 ){
        fwrite(buffer, nCount, 1, fp);
    }
    printf("File transfer success!\n");

    fclose(fp);
}