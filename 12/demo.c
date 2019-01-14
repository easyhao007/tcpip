#include <stdio.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>


#define BUF_SIZE 1024
int main()
{
    fd_set reads , temps;
    struct timeval timeout;

    int result , str_len;
    char buf[BUF_SIZE];

    FD_ZERO(&reads);
    FD_SET(0 , &reads);

    while(1){
        temps = reads;
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;

        result = select(1 , &reads , NULL , NULL , &timeout); 
        if(result == -1){
            puts("select() error!");
            break;
        }
        else if(result == 0){
            puts("time-out !");
        }
        else{
            if(FD_ISSET(0 , &temps))
            {
                str_len = read(0 , buf , BUF_SIZE);
                buf[str_len] = 0;
                printf("message from console: %s" , buf);
            }
        }
    }
    return 0;
}

