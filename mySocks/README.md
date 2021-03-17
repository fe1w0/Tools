# socks 代理工具🧦

## 推荐与参考文章、项目

[linux网络编程系列(二)-socket套接字基本概念详解 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/75806149)

[RFC 1928 - SOCKS 5 协议中文文档「译」 - 光韵流转 (quarkay.com)](https://www.quarkay.com/code/383/socks5-protocol-rfc-chinese-traslation)

[用c语言写一个socks5代理服务器 | 木枣粽子 | BLOG (muzaozong.com)](https://www.muzaozong.com/网络/用c语言写一个socks5代理服务器/#应用架构)

[Socks协议 (qq.com)](https://mp.weixin.qq.com/s/Nsb86MFCjo-PbWnnvrfgUA)

该项目改于[mzz-bridge-c](https://github.com/muzaozong/mzz-bridge-c/tree/v1.0),使用Linux环境,支持`RFC 1929`用户验证和自带`AES-CTR`加密,其中`#include "aes/aes.hpp"`是基于**[ tiny-AES-c](https://github.com/kokke/tiny-AES-c)**

## 使用方法

```bash
🧦 Usage:
Client: -P [local port] -c -h [remote ip] -p [remote port]
Server: -P [local port] -s -u [username] -w [password]
🔔 Finish
```

![image-20210309195134514](http://img.xzaslxr.xyz/image-20210309195134514.png)

* 加密后流量

![image-20210309195338646](http://img.xzaslxr.xyz/image-20210309195338646.png)

仔细观察,可以发现流量在认证部分,还是比较明显的,但完全可以添加垃圾数据,大致思路就是在后面放无用的数据。为什么无用,因为在检验认证过程中,采取的方法是读取固定长度的buffer,不太可能去误读取垃圾数据段。

## 还存在的问题

当`Client`端强制关闭时,socket 暂时无法使用。还有一个安全上的问题,流量还未混淆,以及可以被重放攻击。

![image-20210309195831991](http://img.xzaslxr.xyz/image-20210309195831991.png)

## 总结

感谢[用c语言写一个socks5代理服务器 | 木枣粽子 | BLOG (muzaozong.com)](https://www.muzaozong.com/网络/用c语言写一个socks5代理服务器/#应用架构)前辈的分享和`iyzyi`的帮助。

应对重放攻击,本来想在socks协议上添加上一个挑战与响应的机制,但不太好实现,要重新写一个类似`proxychains`的工具了,或者在`Client`端,对发包先进行检查,当发现是第一个包是,对第一个包添加挑战与响应的机制,原理和实习也可以参考AES加密部分。