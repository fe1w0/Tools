//
// Created by 22343 on 2021/3/16.
//

#include "server.h"

void serverStart(Config config) {
    //��ʼ�� DLL
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    //�����׽���
    SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    //���׽���
    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));  //ÿ���ֽڶ���0���
    sockAddr.sin_family = PF_INET;  //ʹ��IPv4��ַ
    sockAddr.sin_addr.s_addr = htonl(INADDR_ANY);  //�����IP��ַ
    sockAddr.sin_port = htons(config.port);  //�˿�
    bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
    listen(servSock, 20);


    //�������״̬
    printf("Enter the monitoring state\n");

    SOCKADDR clntAddr;
    int  nSize = sizeof(SOCKADDR);
    SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);

    recvFile(config, clntSock);

    //�ر��׽���
    closesocket(clntSock);
    closesocket(servSock);
    //��ֹ DLL ��ʹ��
    WSACleanup();

    //    system("pause");
    return;
}

void recvFile(Config  config, SOCKET sock) {
    printf("%s file waiting to be received\n", config.fileName);

    //�������ļ��������ļ��Ƿ��ܴ����ɹ�
    char* fileName = config.fileName;
    FILE* fp = fopen(fileName, "wb");  //�Զ����Ʒ�ʽ�򿪣��������ļ�
    if (fp == NULL) {
        printf("Cannot open file, press any key to exit!\n");
        system("pause");
        exit(0);
    }

    char buffer[BUF_SIZE] = { 0 };  //�ļ�������
    int nCount;
    while ((nCount = recv(sock, buffer, BUF_SIZE, 0)) > 0) {
        fwrite(buffer, nCount, 1, fp);
    }
    printf("File transfer success!\n");

    fclose(fp);
}