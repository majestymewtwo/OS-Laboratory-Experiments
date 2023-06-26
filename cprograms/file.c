#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char *argv[]) // Getting input from bash terminal
{
    int n, fd;
    char buff[50];
    if (argc < 2)
    {
        printf("Input file not specified %s filename \n", argv[0]);
        exit(0);
    }
    fd = open(argv[1], 0);
    if (fd != -1)
    {
        while ((n = read(fd, buff, sizeof(buff))) > 0)
            write(1, buff, n);
    }
    else
    {
        char ch;
        printf("File does not exist. ..\n");
        printf("Do u wish to create a new file\n");
        scanf("%c", &ch);
        if (ch == 'y' || ch == 'Y')
        {
            printf("\nEnter content of file : \n");
            int fd1 = creat(argv[1], 2);
            char attr[25] = "chmod +rw ";
            strcat(attr, argv[1]);
            system(attr);
            n = read(1, buff, sizeof(buff));
            write(fd1, buff, n);
            close(fd1);
            fd = open(argv[1], 0);
            printf("\nContent of the file %s is : \n", argv[0]);
            while ((n = read(fd1, buff, sizeof(buff))) > 0)
                write(1, buff, n);
        }
    }
}