#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "config.h"
#include "client.h"
#include "server.h"
#include "iostream"


int main(int argc, char *argv[]) {
    struct Config config;
    int opt;
    if (argc == 1){
        printf("🧦 Usage:\nClient: -P [local port] -c -h [remote ip] -p [remote port]\nServer: -P [local port] -s -u [username] -w [password]\n");
    }
    opterr = 0;
    while ((opt = getopt(argc, argv, "P:csh:u:w:p:")) != EOF) {
        switch (opt) {
            case 'P': config.localPort = atoi(optarg); break;
            case 'c': config.client = 1; break;
            case 's': config.server = 1; break;
            case 'h': config.serverHost = optarg; break;
            case 'p': config.serverPort = atoi(optarg); break;
            case 'u': config.username = optarg; break;
            case 'w': config.password = optarg; break;
        }
    }
    signal(SIGCHLD, SIG_IGN);// 对 SIGCHLD 进程信号,忽视处理
//    config.server =1 ;
//    config.username = "test";
//    config.password = "test";
//    config.localPort = 8848;
    if (config.client) {
        startClient(config);
    } else if (config.server) {
        printf("🧦 Config: \n   Username: %s\n   Password: %s\n",config.username,config.password);
        startServer(config);
    }
    printf("🔔 Finish\n");
    return 0;
}