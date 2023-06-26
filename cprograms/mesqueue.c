#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <sys/wait.h>

char name[50];
struct
{
    long mtype;
    char mtext[50];
} message; // Structure to hold the message

int main()
{
    int pid, len, qid;

    system("clear"); // Clears the console screen
    printf("\n Inter Process communication using message queue \n");
    qid = msgget((key_t)13, IPC_CREAT | 0666); // Message queue is created, IPC_CREAT is a flag which tells to create message queue if it does not exist, with permission 0666 (in octal it means read and write)
    printf("\n\nMessage queue is created\n");

    if (qid == -1)
    {
        printf("\nMessage queue is not created \n");
        exit(1);
    }

    printf("\nThe value of qid is %d\n", qid);
    printf("\nEnter the message for communication: ");
    scanf("%s", name);
    strcpy(message.mtext, name); // Copies the message to the struct instance
    message.mtype = 1;
    len = strlen(message.mtext);
    pid = fork();
    printf("\n The value of pid is %d \n", pid);

    if (pid == 0)
    {
        msgsnd(qid, &message, len, IPC_NOWAIT);
        printf("\n\nMESSAGE SENT BY CHILD PROCESS\n");
    }

    if (pid > 0)
    {
        wait(NULL);
        msgrcv(qid, &message, sizeof(message.mtext), 0, IPC_NOWAIT | MSG_NOERROR);
        printf("\nMESSAGE RECEIVED BY PARENT PROCESS\n");
        printf("\nReceived message is %s\n", message.mtext);
    }

    if (pid == -1)
    {
        printf("\nError in creating a child\n");
        exit(1);
    }

    return 0;
}
