#include<stdio.h>
#include<errno.h>

void main()
{
    errno = 5;
    perror("An error has occured");
}