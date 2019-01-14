#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    printf("ready to start udp client\n");
    
    struct sockaddr_in s_server;
    s_server.sin_family = PF_BRIDGE;
    s_server.sin_addr.s_addr = htonl(INADDR_ANY);
    s_server.sin_port = htons(8012);

    struct sockaddr_in s_client;

    int sockfd , ret ;
    socklen_t s_server_len;

    sockfd = socket(PF_INET , SOCK_DGRAM ,0);
    if(sockfd == -1){
        printf("error to socket server\n");
        return -1;
    }
    
    s_server_len = sizeof(s_server);
    ret = bind(sockfd , (struct sockaddr*)&s_server , s_server_len);
    if(ret == -1){
        printf("error to bind server\n");
        return -1;
    }
    

    char* buf = (char*)malloc(1024);

    socklen_t s_client_len = sizeof(s_client);
    while(1){
        memset(buf ,0 , sizeof(buf));
        ssize_t nrecv = recvfrom(sockfd , buf , 1024 , 0 , (struct sockaddr*)&s_client , &s_client_len);
        if(nrecv == -1){
            printf("recv buf faild\n");
            continue;
        }

        printf("recv: %s\n" , buf);
    }    

    close(sockfd);
    free(buf);
    
    return 0;
}

