//
// Created by 22343 on 2021/3/16.
//

#ifndef ARTERIAL_SERVER_H
#define ARTERIAL_SERVER_H

#include "config.h"
#include <stdio.h>
#include <winsock2.h>
#include "fstream"
#include "iostream"
#include "cstring"

#pragma comment (lib, "ws2_32.lib")  //���� ws2_32.dll

/**
 * �����ļ���������
 * @param config
 */
void serverStart(Config config);
/*
 * �����ļ�
 */
void recvFile(Config  config, SOCKET sock);

#endif //ARTERIAL_SERVER_H
