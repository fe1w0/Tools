//
// Created by 22343 on 2021/3/16.
//

#ifndef ARTERIAL_CONFIG_H
#define ARTERIAL_CONFIG_H
#define BUF_SIZE 1024

struct Config {
    int port;   // -p [port], ���ؼ����˿� OR  �ͻ���ģʽ�£���Ҫָ������˶˿�
    int client = 0;      // �ͻ���ģʽ
    int server = 0;      // �����ģʽ
    char* serverHost;  // �ͻ���ģʽ�£���Ҫָ������˵�ַ
    char* fileName; //ָ�����ļ���
};

#endif //ARTERIAL_CONFIG_H
