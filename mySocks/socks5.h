//
// Created by 22343 on 2021/2/27.
//

#ifndef MYSOCKS_SOCKS5_H
#define MYSOCKS_SOCKS5_H



#include "common.h"

#define SOCK5_VALIDATE_REQUEST_MAX_LENGTH 257
#define SOCK5_BUILD_REQUEST_MAX_LENGTH 263
#define SOCK5_AUTHENTICATION_REQUEST_MAX_LENGTH 513

struct Sock5ValidateRequest {
    Byte version;
    Byte methodNum;
    Byte *methods;
};

struct Sock5ValidateResponse {
    Byte version;
    Byte method;
};

struct Sock5AuthRequest{
    Byte version;
    Byte usernameLen;
    Byte *username;
    Byte passwordLen;
    Byte *password;
};

struct Sock5AuthResponse{
    Byte version;
    Byte Status;
};


struct Sock5BuildRequest {
    Byte version;
    Byte cmd;
    Byte rsv;
    Byte atyp;
    Byte addrLength;  // 地址长度
    Byte *dstAddr;
    ushort dstPort;
};

struct Sock5BuildResponse {
    Byte version;
    Byte rep;
    Byte rsv;
    Byte atyp;
    Byte addrLength; // 地址长度
    Byte *bndAddr;
    ushort bndPort;
};

/**
 * 读取sock5验证请求
 * @param buffer
 * @return
 */
struct Sock5ValidateRequest Sock5ValidateRequest_read(Byte *buffer);

/**
 * 获取Sock5ValidateResponse的总长度
 * @param response
 * @return
 */
size_t Sock5ValidateResponse_getLength(struct Sock5ValidateResponse response);

/**
 * 将sock5验证响应转换为字符串
 * @param response
 * @return
 */
char* Sock5ValidateResponse_toString(struct Sock5ValidateResponse response);


/**
 * 读取socks5身份验证请求
 * @param buffer
 * @return
 */
struct Sock5AuthRequest Sock5AuthRequest_read(Byte *buffer);

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
char* Sock5AuthResponse_toString(struct Sock5AuthResponse response);
/**
 * 读取sock5建立连接请求
 * @param buffer
 * @return
 */
struct Sock5BuildRequest Sock5BuildRequest_read(Byte *buffer);

/**
 * 获取Sock5BuildResponse的总长度
 * @param response
 * @return
 */
size_t Sock5BuildResponse_getLength(struct Sock5BuildResponse response);

/**
 * 将sock5建立连接请求转换为字符串
 * @param response
 * @return
 */
char* Sock5BuildResponse_toString(struct Sock5BuildResponse response);


#endif //MYSOCKS_SOCKS5_H
