//
// Created by 22343 on 2021/3/16.
//

#ifndef ARTERIAL_CLIENT_H
#define ARTERIAL_CLIENT_H
#include <stdlib.h>
#include <WinSock2.h>
#include "cstring"
#include "fstream"
#include "iostream"
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")  //���� ws2_32.dll

#include "config.h"

/*
 * ��������,�����ص�һ��IPV4��ַ
 */
char* getIPV4(char* domainName);

/*
 * �����ļ�����ͻ���
 */
void clientStart(Config config);

/*
* �����ļ�
*/
void sendFile(Config config, SOCKET sock);

#endif //ARTERIAL_CLIENT_H
