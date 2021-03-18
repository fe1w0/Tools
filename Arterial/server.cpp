//
// Created by 22343 on 2021/3/16.
//

#include "server.h"

void serverStart(Config config) {
    //初始化 DLL
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    //创建套接字
    SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    //绑定套接字
    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));  //每个字节都用0填充
    sockAddr.sin_family = PF_INET;  //使用IPv4地址
    sockAddr.sin_addr.s_addr = htonl(INADDR_ANY);  //具体的IP地址
    sockAddr.sin_port = htons(config.port);  //端口
    bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
    listen(servSock, 20);


    //进入监听状态
    printf("Enter the monitoring state\n");

    SOCKADDR clntAddr;
    int  nSize = sizeof(SOCKADDR);
    SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);

    recvFile(config, clntSock);

    //关闭套接字
    closesocket(clntSock);
    closesocket(servSock);
    //终止 DLL 的使用
    WSACleanup();

    //    system("pause");
    return;
}

void recvFile(Config  config, SOCKET sock) {
    printf("%s file waiting to be received\n", config.fileName);

    //先输入文件名，看文件是否能创建成功
    char* fileName = config.fileName;
    FILE* fp = fopen(fileName, "wb");  //以二进制方式打开（创建）文件
    if (fp == NULL) {
        printf("Cannot open file, press any key to exit!\n");
        system("pause");
        exit(0);
    }

    char buffer[BUF_SIZE] = { 0 };  //文件缓冲区
    int nCount;
    while ((nCount = recv(sock, buffer, BUF_SIZE, 0)) > 0) {
        fwrite(buffer, nCount, 1, fp);
    }
    printf("File transfer success!\n");

    fclose(fp);
}