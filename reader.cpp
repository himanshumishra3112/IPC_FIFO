#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 5000

int main()
{
    int fd1;
    char * myfifo = "myfifo";
    mkfifo(myfifo, 0666);
    char str1[BUF_SIZE];

    while (1)
    {

        fd1 = open(myfifo,O_RDONLY);
        read(fd1, str1, BUF_SIZE);
        printf("Received FIFO data:\n");
        printf("===================\n\n");

        printf("%s\n\n", str1);
        printf("===================\n\n");
        close(fd1);
    }
    return 0;
}
