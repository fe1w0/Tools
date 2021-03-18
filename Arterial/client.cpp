//
// Created by 22343 on 2021/3/16.
//

#include "client.h"

char* getIPV4(char* domainName) {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    struct hostent* host = gethostbyname(domainName);
    return inet_ntoa(*(struct in_addr*)host->h_addr_list[0]);
}

void clientStart(Config config) {
    //初始化DLL
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    //创建套接字
    SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    //向服务器发起请求
    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));  //每个字节都用0填充
    sockAddr.sin_family = PF_INET;

    char* serverHost = getIPV4(config.serverHost);
    sockAddr.sin_addr.s_addr = inet_addr(serverHost);

    sockAddr.sin_port = htons(config.port);

    printf("The client is created\n");
    connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
    //接收服务器传回的数据
    sendFile(config, sock);
    //关闭套接字
    closesocket(sock);
    //终止使用 DLL
    WSACleanup();
    //    system("pause");
    return;
}

void sendFile(Config config, SOCKET clntSock) {
    printf("%s file waiting to be sent\n", config.fileName);
    char* fileName = config.fileName;
    FILE* fp = fopen(fileName, "rb");
    if (fp == NULL) {
        printf("Cannot open file, press any key to exit! \n");
        system("pause");
        exit(0);
    }
    char buffer[BUF_SIZE] = { 0 };
    int nCount;

    //循环发送数据，直到文件结尾
    while ((nCount = fread(buffer, 1, BUF_SIZE, fp)) > 0) {
        send(clntSock, buffer, nCount, 0);
    }

    shutdown(clntSock, SD_SEND);  //文件读取完毕，断开输出流，向客户端发送FIN包
    recv(clntSock, buffer, BUF_SIZE, 0); //阻塞，等待客户端接收完毕

    fclose(fp);
    printf("File transferred\n");
}