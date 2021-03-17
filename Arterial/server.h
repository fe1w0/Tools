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

#pragma comment (lib, "ws2_32.lib")  //加载 ws2_32.dll

/**
 * 开启文件传输服务端
 * @param config
 */
void serverStart(Config config);

void sendFile(Config config,SOCKET clntSock);

#endif //ARTERIAL_SERVER_H
