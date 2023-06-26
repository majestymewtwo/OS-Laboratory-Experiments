#include <stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>

void main()
{
    int shmid;        // Holds shared memory identifier
    key_t key = 0x10; // Holds the key value for shared memory operations

    shmid = shmget(key, 110, IPC_CREAT | 0666); // Key indicates the shared memory segment to access, IPC_CREAT | 0666 combined flags tell to create a shared memory with specified key, of 100 bytes size and read+write permission
    if (shmid < 0)
        printf("\nFirst SHMID failed\n");
    else
        printf("\nFirst SHMID succeeded. id=%d\n", shmid);

    shmid = shmget(key, 100, IPC_CREAT | 0666);
    if (shmid < 0)
        printf("\nSecond SHMID failed\n");
    else
        printf("\nSecond SHMID succeeded. id=%d\n", shmid);

    shmid = shmget(key, 90, IPC_CREAT | 0666);
    if (shmid < 0)
        printf("\nThird SHMID failed\n");
    else
        printf("\nThird SHMID succeeded. id=%d\n", shmid);
}
