//
// Created by 22343 on 2021/3/16.
//

#ifndef ARTERIAL_CONFIG_H
#define ARTERIAL_CONFIG_H
#define BUF_SIZE 1024

struct Config{
    int port;   // -p [port], 本地监听端口 OR  客户端模式下，需要指定服务端端口
    int client =0;      // 客户端模式
    int server =0;      // 服务端模式
    char * serverHost;  // 客户端模式下，需要指定服务端地址
    char * fileName; //指定的文件名
};

#endif //ARTERIAL_CONFIG_H
