#include <iostream>
#include "config.h"
#include <stdlib.h>
#include <stdio.h>
#include "client.h"
#include "server.h"

int main(int argc, char *argv[]) {
    struct Config config;
    if (argc == 1){
        printf("Usage:\n   Server: -s -f [File name] -p [local port]\n   Client: -c -f [File name] -h [remote host] -p [remote port]\n");
    }
//    for(int count = 0; count < argc; count++ )
//        std::cout << "  argv[" << count << "]   "
//             << argv[count] << "\n";
    for(int count = 1;count < argc;count++){
        if( strcmp(argv[count] ,"-s") == 0){ config.server = 1;}
        else if(strcmp(argv[count],"-c") == 0){ config.client = 1;}
        else if(strcmp(argv[count],"-f")== 0){ config.fileName = argv[++count];}
        else if(strcmp(argv[count],"-h") == 0){ config.serverHost = argv[++count];}
        else if(strcmp(argv[count] ,"-p") == 0){ config.port = atoi(argv[++count]);}
    }

    /*
     * Just For Test
     */
//    config.client = 1;
//    config.serverHost = "localhost";
//    config.port = 9001;
//    config.fileName = "test";


    if(config.client){
        clientStart(config);
    } else if(config.server){
        serverStart(config);
    }
}