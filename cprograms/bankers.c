#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Max[10][10], need[10][10], alloc[10][10], avail[10], completed[10], safeSequence[10];
    int p, r, i, j, process, count;
    count = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &p);

    for (i = 0; i < p; i++)
        completed[i] = 0;

    printf("\nEnter the number of resources: ");
    scanf("%d", &r);

    printf("\nEnter the Max Matrix for each process:\n"); // Max matrix for each process
    for (i = 0; i < p; i++)
    {
        printf("For process %d:\n", i + 1);
        for (j = 0; j < r; j++)
            scanf("%d", &Max[i][j]);
    }

    printf("\nEnter the allocation for each process:\n"); // Allocation matrix for each process
    for (i = 0; i < p; i++)
    {
        printf("For process %d:\n", i + 1);
        for (j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);
    }

    printf("\nEnter the Available Resources:\n");
    for (i = 0; i < r; i++)
        scanf("%d", &avail[i]);

    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            need[i][j] = Max[i][j] - alloc[i][j]; // Need matrix = Max matrix - allocation matrix

    do
    {
        printf("\nMax matrix:\tAllocation matrix:\n");
        for (i = 0; i < p; i++)
        {
            for (j = 0; j < r; j++)
                printf("%d ", Max[i][j]);
            printf("\t\t");
            for (j = 0; j < r; j++)
                printf("%d ", alloc[i][j]);
            printf("\n");
        }
        process = -1;
        for (i = 0; i < p; i++) // Checking to see if any process can be allocated with available resource matrix
        {
            if (completed[i] == 0) // if not completed
            {
                process = i;
                for (j = 0; j < r; j++)
                {
                    if (avail[j] <= need[i][j]) // Will allocated only if need matrix < available matrix
                    {
                        process = -1;
                        break;
                    }
                }
            }
            if (process != -1) // This means process has been allocated
                break;
        }

        if (process != -1)
        {
            printf("\nProcess %d runs to completion!", process + 1);
            safeSequence[count] = process + 1;
            count++;

            for (j = 0; j < r; j++)
            {
                avail[j] += alloc[process][j]; // Increasing available matrix after successfully allocating to process
                alloc[process][j] = 0;         // Setting the allocations to 0 because it has already been allocated
                Max[process][j] = 0;           // Max matrix is also set 0
                completed[process] = 1;        // Process is marked as completed after successful allocation
            }
        }
    } while (count != p && process != -1); // Will keep looping through until all process have been allocated

    if (count == p) // This means the all processes are allocated
    {
        printf("\nThe system is in a safe state!\n");
        printf("Safe Sequence: < ");
        for (i = 0; i < p; i++)
            printf("%d ", safeSequence[i]);
        printf(">\n");
    }
    else
        printf("\nThe system is in an unsafe state!\n"); // This means not all have been allocated and system might cause deadlocks

    return 0;
}
