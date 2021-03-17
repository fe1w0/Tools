//
// Created by 22343 on 2021/2/27.
//

#include "socks5.h"
#include <string.h>
#include <stdlib.h>
#include "common.h"


struct Sock5ValidateRequest Sock5ValidateRequest_read(Byte *buffer) {
    struct Sock5ValidateRequest request;
    request.version = buffer[0];
    request.methodNum = buffer[1];
    request.methods = (Byte *)malloc(request.methodNum); // 分配所需的内存空间，并返回一个指向它的指针
    Byte_copyN(request.methods, buffer + 2, request.methodNum);// 前面不是限定了buffer长度为3,后面就只有一个
    return request;
}

size_t Sock5ValidateResponse_getLength(struct Sock5ValidateResponse response) {
    return 2;
}

char* Sock5ValidateResponse_toString(struct Sock5ValidateResponse response) {
    Byte *result = (Byte *)malloc(3);// 三个字节,用来两
    int p = 0;
    result[p++] = response.version;
    result[p] = response.method;
    return (char *)result;
}

/**
 * 读取socks5身份验证请求
 * @param buffer
 * @return
 */
struct Sock5AuthRequest Sock5AuthRequest_read(Byte *buffer){
    struct Sock5AuthRequest request;
    request.version = buffer[0];
    request.usernameLen = buffer[1];
    request.username = (Byte *)malloc(request.usernameLen); // 分配所需的内存空间，并返回一个指向它的指针
    Byte_copyN(request.username, buffer + 2, request.usernameLen);// 前面不是限定了buffer长度为3,后面就只有一个
    request.passwordLen = buffer[2+request.usernameLen];
    request.password =  (Byte *)malloc(request.passwordLen);
    Byte_copyN(request.password, buffer + 3 + request.usernameLen, request.passwordLen);
    return request;
}

/**
 * 获取Sock5AuthResponse的总长度
 * @param response
 * @return
 */
size_t Sock5AuthResponse_getLength(struct Sock5AuthResponse response);
/**
 * 将sock5身份验证响应转换为字符串
 * @param response
 * @return
 */
char* Sock5AuthResponse_toString(struct Sock5AuthResponse response){
    Byte *result = (Byte *)malloc(3);// 三个字节,用来两
    int p = 0;
    result[p++] = response.version;
    result[p] = response.Status;
    return (char *)result;
}


struct Sock5BuildRequest Sock5BuildRequest_read(Byte *buffer) {
    struct Sock5BuildRequest request;
    int p = 0;
    request.version = buffer[p++];
    request.cmd = buffer[p++];
    request.rsv = buffer[p++];
    request.atyp = buffer[p++];
    switch (request.atyp) {
        case 0x01: request.addrLength = 4; break; // IPV4
        case 0x03: request.addrLength = buffer[p++]; break; // 域名,协议上没细谈,但确实有一段一字表示长度,也就说明总的最大长度为 263
        case 0x04: request.addrLength = 16; break; //IPV6
        default: request.addrLength = 0;
    }
    request.dstAddr = (Byte *)malloc(request.addrLength);
    Byte_copyN(request.dstAddr, buffer + p, request.addrLength);
    p += request.addrLength;
    request.dstPort = (buffer[p] << 8) + buffer[p+1];
    return request;
}

size_t Sock5BuildResponse_getLength(struct Sock5BuildResponse response) {
    return response.addrLength + (response.atyp == 0x03 ? 7 : 6);
}

char* Sock5BuildResponse_toString(struct Sock5BuildResponse response) {
    Byte *result = (Byte *)malloc(Sock5BuildResponse_getLength(response));
    int p = 0;
    result[p++] = response.version;
    result[p++] = response.rep;
    result[p++] = response.rsv;
    result[p++] = response.atyp;
    if (response.atyp == 0x03) {
        result[p++] = response.addrLength;
    }
    Byte_copyN(result + p, response.bndAddr, response.addrLength);
    p += response.addrLength;
    result[p++] = (Byte)(response.bndPort >> 8);
    result[p] = (Byte)(response.bndPort & 0xff);
    return (char *)result;
}
