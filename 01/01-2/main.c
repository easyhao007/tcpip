#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>

int main()
{
    int fd = open("test.txt" , O_CREAT | O_RDWR);
    if(fd < 0){
        printf("error to open the file\n");
        return -1;
    }
    
    char* buf = "123456789";
    int buf_len = sizeof(buf);
    int nread = write(fd , buf , buf_len);
    if(nread != buf_len){
        printf("write buff faild\n");
        return -1;
    }
    close(fd);
    return 0;
}

