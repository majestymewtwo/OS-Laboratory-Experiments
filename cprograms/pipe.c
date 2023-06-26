#include <stdio.h>
#include <stdlib.h>

void main()
{
    int pid, ppid, pdes[2], n, a;
    printf("\nInterprocess communication using pipes\n");

    if (pipe(pdes) == -1) // Used to create a pipe and store the pipe file descriptors in pdes
    {
        printf("\nError creating pipe\n");
        exit(1);
    }
    else
    {
        pid = fork();
        if (pid == -1)
            printf("\nError creating child process\n");
        else if (pid)
        {
            close(pdes[0]); // Closes read end of the pipe in parent process
            printf("\nParent is %d\n", getpid());
            printf("\nChild process is %d\n", pid);
            printf("\nEnter a number: ");
            scanf("%d", &a);
            write(pdes[1], &a, sizeof(a)); // Adds the value to the write end of the pipe
        }
        else
        {
            close(pdes[1]);               // Closes write end of the child process
            read(pdes[0], &n, sizeof(n)); // Reads data from the read end of the pipe
            if (n % 2 == 0)
                printf("\nThe number %d is even\n", n);
            else
                printf("\nThe number %d is odd\n", n);
        }
    }
}
