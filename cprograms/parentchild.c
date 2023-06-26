#include <stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#define MAX_COUNT 5

void parentprocess();
void childprocess();
void main()
{
    pid_t pid;
    pid = fork(); //This function splits the current process into 2 processes, PARENT and CHILD. Parent process will have some PID like 1340, 1412 but child process PID will be 0
    printf("Current process ID is %d\n", pid);
    if (pid != 0)
        parentprocess();
    else
        childprocess();
}
void childprocess()
{
    int k;
    k = getpid();
    printf("\n******INSIDE CHILD PROCESS*******\n\n");
    printf("\nThe PID of child process is %d \n", k);
    printf("The output for execlp system call is:\n");
    execlp("/bin/ls", "ls", NULL); //This function is used for executing linux commands through C
    printf("\n");
}
void parentprocess()
{
    int i, k;
    k = getpid(); //This function gets the current PID of the executing process
    wait(); //This function makes the parent process to pause execution until child processes have completed execution
    printf("\n******INSIDE PARENT PROCESS*******\n\n");
    for (i = 1; i <= MAX_COUNT; i++)
        printf("The line from parent value = %d\n", i);
    printf("The parent process is done\n");
    printf("getpid() value of process id is %d\n", k);
    exit(0);
}