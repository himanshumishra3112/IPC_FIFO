#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 5000

int main()
{
    int fd;
    char * myfifo = "myfifo";
    mkfifo(myfifo, 0666);
    while (1)
    {
        fd = open(myfifo, O_WRONLY);

        FILE *fp;
        char str[BUF_SIZE], fname[50], str2[50];
        printf("Enter the file name:");
        scanf("%s",fname);

        if ((fp= fopen(fname, "r")) == NULL) {
            printf("cannot open file");
            return 1;
        }
        while(!feof(fp)) {
            fgets(str2,50-1,fp);
            strncat(str,str2,strlen(str2));
        }
        str[strlen(str) -1 ] = '\0';
        fclose(fp);

        write(fd, str, strlen(str)+1);
        close(fd);
        str[0] = '\0';
    }
    return 0;
}
