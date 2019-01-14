#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    printf("Hello This is Server\n");
    int ret = 0;
    struct sockaddr_in s_server;
    struct sockaddr_in s_clinet;
    socklen_t s_server_len , s_client_len;

    int sockfd = socket(PF_INET , SOCK_STREAM , 0);
    if(sockfd == -1){
        printf("errro to create socket\n");
        return -1;
    }

    s_server.sin_family = PF_INET;
    s_server.sin_addr.s_addr = htonl(INADDR_ANY);
    s_server.sin_port = htons(8081);
    s_server_len = sizeof(s_server);
    ret = bind(sockfd , (struct sockaddr*)&s_server , s_server_len);   
    if(ret != 0){
        printf("error to bind to server\n");
        return -1;
    }

    ret = listen(sockfd , 1024);
    if(ret != 0){
        printf("error to listen socket\n");
        return -1;
    }

    char *buf = (char*)malloc(128);
    while(1){
        int connfd = accept(sockfd , (struct sockaddr*)&s_clinet , &s_client_len);
        if(connfd == -1){
            printf("error to accept socket\n");
            return -1;
        }
        ret = recv(connfd, buf , 128 , 0);
        printf("recv:%s\n" , buf);
        ret = send(connfd , buf , 128 , 0);
        if(ret == -1){
            printf("error to send data to client , errno [%d]\n" , errno);
        }
        printf("send data to client success! %d\n" , ret);
        close(connfd);
    }
    close(sockfd);
    return 0;
}

