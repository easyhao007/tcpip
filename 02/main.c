#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

int main()
{
    // 创建TCP -> 可靠的，有序的，基于字节的面向有连接的数据传输方式
    int sockfd = socket(PF_INET , SOCK_STREAM , 0);
    // 创建UDP -> 不可靠，不按顺序，以数据的高速传输为目的的套接字
    int sockfd = socket(PF_INET , SOCK_DGRAM , 0);
    /*
     * @brief 创建套接字
     *
     * @domain  :协议簇
     * @type    :套接字类型
     * @protocol:协议
     */
    return 0;
}

