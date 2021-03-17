//
// Created by 22343 on 2021/2/27.
//

#include "common.h"
#include <stdio.h>
#include <sys/socket.h>
#include <memory.h>
#include <netinet/in.h>
#include "common.h"
#include "exception.h"
#include "aes/aes.hpp"

#define RETRY_TIME 10

Byte* Byte_copyN(Byte *dst, const Byte *src, size_t n) {
    memcpy(dst, src, n);
    return dst;
}

char* Byte_arrayToStr(Byte *src, size_t n) {
    char* result = (char *)malloc(n + 1);
    memcpy(result, src, n);
    result[n] = '\0';
    return result;
}

int	retryConnect(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    for (int i = 0; i < RETRY_TIME; i++) {
        int result = connect(sockfd, addr, addrlen);
        if (result >= 0) {
            return result;
        }
    }
    return -1;
}

ssize_t retryRecv(int sockfd, void *buf, size_t len) {
    for (int i = 0; i < RETRY_TIME; i++) {
        ssize_t result = recv(sockfd, buf, len, 0);
        if (result >= 0) {
            return result;
        }
    }
    return -1;
}

ssize_t retrySend(int sockfd, const void *buf, size_t len) {
    for (int i = 0; i < RETRY_TIME; i++) {
        ssize_t result = send(sockfd, buf, len, 0);
        if (result >= 0) {
            return result;
        }
    }
    return -1;
}

int createListeningSocket(int port) {
    int listeningSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //  可以见这篇文章 http://c.biancheng.net/view/2131.html,返回socket 的文件描述符
    if (listeningSock < 0) {
        return SERVER_SOCKET_CREATE_ERROR;
    }

    int optval;
    setsockopt(listeningSock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr)); // void *memset(void *s, int ch, size_t n)  函数解释：将s中当前位置后面的n个字节 （typedef unsigned int size_t ）用 ch 替换并返回 s 。
    serverAddr.sin_family = AF_INET; //使用IPv4地址
    serverAddr.sin_port = htons(port); // htons是将整型变量从主机字节顺序转变成网络字节顺序， 就是整数在地址空间存储方式变为高位字节存放在内存的低地址处。
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); // 将一个32位数从主机字节顺序转换成网络字节顺序

    if (bind(listeningSock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) != 0) {
        return SERVER_SOCKET_BIND_ERROR;
    }

    if (listen(listeningSock, 30) != 0) { // sock 为需要进入监听状态的套接字，backlog 为请求队列的最大长度。
        return SERVER_SOCKET_LISTEN_ERROR;
    }

    return listeningSock;
}

void encryptData(uint8_t * buffer,ssize_t n){
    struct AES_ctx ctx;
//    printf("original raw:\n");
//    for (int i = 0; i < n; ++i) {
//        printf("%.2x", buffer[i]);
//    }
//    printf("\n");
    uint8_t key[] = "lxr@xzas@#$%WERT";
    uint8_t iv[] = "xzas@lxr@WSX3edc";
    AES_init_ctx_iv(&ctx,key,iv);
    AES_CTR_xcrypt_buffer(&ctx,buffer,n);
//    printf("Changed raw:\n");
//    for (int i = 0; i < n; ++i) {
//        printf("%.2x", buffer[i]);
//    }
//    printf("\n");
}

void forwardData(int srcSock, int dstSock, int encryption) {
    char buffer[8192];
    ssize_t n;//ssize_t 这个数据类型用来表示可以被执行读写操作的数据块的大小
    while ((n = retryRecv(srcSock, buffer, 8000)) > 0) {
        if(encryption == 1){ // encryption = 1,执行加密或解密
            encryptData((uint8_t *)buffer,n);
        }
        if (retrySend(dstSock, buffer, (size_t)n) < 0) {
            break;
        }
    }
    shutdown(srcSock, SHUT_RDWR); // 断开tcp 链接
    shutdown(dstSock, SHUT_RDWR);
}