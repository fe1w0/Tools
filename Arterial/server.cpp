//
// Created by 22343 on 2021/3/16.
//

#include "server.h"

void serverStart(Config config){
    //初始化 DLL
    WSADATA wsaData;
    WSAStartup( MAKEWORD(2, 2), &wsaData);
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


    sendFile(config,clntSock);

    //关闭套接字
    closesocket(clntSock);
    closesocket(servSock);
    //终止 DLL 的使用
    WSACleanup();

//    system("pause");
    return ;
}


void sendFile(Config config,SOCKET clntSock){
    printf("%s file waiting to be sent\n",config.fileName);
    char * fileName = config.fileName;
    FILE * fp = fopen(fileName,"rb");
    if(fp == NULL){
        printf("Cannot open file, press any key to exit! \n");
        system("pause");
        exit(0);
    }
    char buffer[BUF_SIZE] = {0};
    int nCount;

    //循环发送数据，直到文件结尾
    while( (nCount = fread(buffer,1,BUF_SIZE,fp)) >0 ){
        send(clntSock,buffer,nCount,0);
    }

    shutdown(clntSock,SD_SEND);  //文件读取完毕，断开输出流，向客户端发送FIN包
    recv(clntSock,buffer,BUF_SIZE,0); //阻塞，等待客户端接收完毕

    fclose(fp);
    printf("File transferred\n");
}