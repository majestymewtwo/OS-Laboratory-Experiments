#include <stdio.h>
int main(int argc, char *argv[]) // Getting input from bash terminal
{
    int n, fd;
    char buff[5]; // Size of buffered reader
    if (argc < 2)
    {
        printf("Input file not specified %s filename \n", argv[0]);
        exit(0);
    }
    fd = open(argv[1], 0); // Opening in read only mode as second argument is 0
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
            int fd1 = creat(argv[1], 2); // creating the file in read and write mode as second argument is 2
            char attr[25] = "chmod +rw ";
            strcat(attr, argv[1]);           // Will concatenate the file name to command, eg : "chmod +rw new.txt"
            system(attr);                    // Will run the command
            n = read(0, buff, sizeof(buff)); // first argument is 0 which means standard input terminal is used to read, second argument is a pointer where the read data is stored, third is the size argument which specifies the maximum amount of bytes to be read from the buffer
            write(fd1, buff, n);
            close(fd1);
            fd = open(argv[1], 0);
            printf("\nContent of the file %s is : \n", argv[0]);
            while ((n = read(fd1, buff, sizeof(buff))) > 0)
                write(1, buff, n);
        }
    }
}