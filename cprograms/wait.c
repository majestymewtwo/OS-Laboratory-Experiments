#include <stdio.h>
void main()
{
    int id, cid, stat;
    if ((id = fork()) == 0)
    {
        printf("\nThis is child process\n");
        printf("\nParent process ID is %d \nStatus ID is %d\n", getpid(), stat);
        printf("\n");
        execl("/bin/date", "date", 0);
        printf("\n");
    }
    cid = wait(&stat);
    printf("\nThis is parent process\n");
    printf("\nID is %d \nStatus is %d \n", cid, stat);
}
