//
// Created by 22343 on 2021/2/27.
//

#ifndef MYSOCKS_CONFIG_H
#define MYSOCKS_CONFIG_H


struct Config {
    int localPort;   // -p [port], 本地监听端口
    int client =0;      // 客户端模式
    int server =0;      // 服务端模式
    char* serverHost;  // 客户端模式下，需要指定服务端地址
    int serverPort;  // 客户端模式下，需要指定服务端端口
    char* username; //服务器模式下,socks5验证可以指定用户名
    char* password; //服务器模式下,socks5验证可以指定密码
};


#endif //MYSOCKS_CONFIG_H
