#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

union data{
    uint16_t num;
    char     str[2];
};

int main()
{
    union data d;
    d.num = 0x1234;
    if(d.str[0] == 0x12 && d.str[1] == 0x34){
        // 高位字节存档到低位地址
        printf("big endia\n");
    }else{
        // 高位字节存放到低位地址
        printf("little endia\n");
    }


    // 字节和网络序转换
    unsigned short host_port = 0x1234;
    unsigned short net_port;

    unsigned long host_addr = 0x12345678;
    unsigned long net_addr;

    net_port = htons(host_port);
    net_addr = htonl(host_addr);

    printf("host ordered port:%#x\n" , host_port);
    printf("net  ordered port:%#x\n" , net_port);

    printf("host ordered addr:%#lx\n" , host_addr);
    printf("net  ordered addr:%#lx\n" , net_addr);



    char* addr1 = "1.2.3.4";
    char* addr2 = "1.2.3.256";

    unsigned long conv_addr = inet_addr(addr1);
    if(conv_addr == INADDR_NONE){
        printf("error to convert addr to net ordered\n");
    }else{
        printf("network ordered integer addr:%#lx \n" , conv_addr);
    }

    conv_addr = inet_addr(addr2);
    if(conv_addr == INADDR_NONE){
        printf("error to convert addr to net ordered\n");
    }else{
        printf("network ordered integer addr:%#lx \n" , conv_addr);
    }

    // sockadddr_in 赋值
    struct sockaddr_in s_server;
    s_server.sin_family = PF_INET;
    s_server.sin_port = htons(80);
    inet_aton(addr1 , &s_server.sin_addr);

    return 0;
}

