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
    //��ʼ��DLL
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    //�����׽���
    SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    //���������������
    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));  //ÿ���ֽڶ���0���
    sockAddr.sin_family = PF_INET;

    char* serverHost = getIPV4(config.serverHost);
    sockAddr.sin_addr.s_addr = inet_addr(serverHost);

    sockAddr.sin_port = htons(config.port);

    printf("The client is created\n");
    connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
    //���շ��������ص�����
    sendFile(config, sock);
    //�ر��׽���
    closesocket(sock);
    //��ֹʹ�� DLL
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

    //ѭ���������ݣ�ֱ���ļ���β
    while ((nCount = fread(buffer, 1, BUF_SIZE, fp)) > 0) {
        send(clntSock, buffer, nCount, 0);
    }

    shutdown(clntSock, SD_SEND);  //�ļ���ȡ��ϣ��Ͽ����������ͻ��˷���FIN��
    recv(clntSock, buffer, BUF_SIZE, 0); //�������ȴ��ͻ��˽������

    fclose(fp);
    printf("File transferred\n");
}