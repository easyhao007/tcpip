#include <stdio.h>
#include <sys/select.h>
#include <sys/types.h>

int main()
{
    printf("Hello world\n");
    fd_set fs;
    FD_ZERO(&fs);
    FD_SET(1 , &fs);
    FD_SET(2 , &fs);
    FD_CLR(1 , &fs);
    printf("1 is set to fdset , %d\n" , FD_ISSET(1 , &fs));
    printf("2 is set to fdset , %d\n" , FD_ISSET(2 , &fs));
    return 0;
}

