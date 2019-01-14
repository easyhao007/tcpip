#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    printf("Hello this is the clinet:\n");
    int ret = 0;

    struct sockaddr_in s_server;
    s_server.sin_family = PF_INET;
    inet_aton("127.0.0.1" , &s_server.sin_addr);
    s_server.sin_port = htons(8081);

    socklen_t s_server_len = sizeof(s_server);

    int sockfd = socket(PF_INET , SOCK_STREAM , 0);
    if(sockfd == -1){
        printf("error to create socket\n");
        return -1;
    }

    ret = connect(sockfd , (struct sockaddr*)&s_server , s_server_len);
    if(ret != 0){
        printf("error to connect to server\n");
        return -1;
    }

    sleep(2);
    char *buf = "12345678";
    int buf_len = sizeof(buf);
    ret = send(sockfd , buf , buf_len , 0);
    if(ret != buf_len){
        printf("send faild\n");
        return 0;
    }
    close(sockfd);
    return 0;
}

