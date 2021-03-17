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

#pragma comment(lib, "ws2_32.lib")  //加载 ws2_32.dll

#include "config.h"

/*
 * 解析域名,并返回第一个IPV4地址
 */
char * getIPV4(char * domainName);

/*
 * 开启文件传输客户端
 */
void clientStart(Config config);

/*
 * 接收文件
 */
void recvFile(Config  config,SOCKET sock);


#endif //ARTERIAL_CLIENT_H
