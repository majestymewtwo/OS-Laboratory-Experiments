#include <stdio.h>
int tt, i, j, temp;
void rrobin(int[], int);

void main()
{
    int btime[10], n, x, z;
    printf("\nROUND ROBIN SCHEDULING ALGORITHM\n");
    printf("\nEnter the no. of process: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter Burst time for the process %d: ", i);
        scanf("%d", &btime[i]);
    }
    printf("Process Name\t\tBurst Time\n");
    for (i = 0; i < n; i++)
        printf("P%d\t\t\t%d\n", i, btime[i]);
    z = 1;
    tt = 0;
    rrobin(btime, n);
    printf("\n");
}
void rrobin(int btime[], int n)
{
    int tslice, j = 0;
    printf("Enter the Time Slicing:");
    scanf("%d", &tslice);
    printf("Process Name\tRemaining Time\tTotalTime");
    while (j < n)
    {
        int flag = 0;
        for (i = 0; i < n; i++)
        {
            if (btime[i] > 0)
            {
                flag = 1;
                if (btime[i] >= tslice)
                {
                    tt += tslice;
                    btime[i] = btime[i] - tslice;
                    printf("\nP%d\t\t%d\t\t%d", i, btime[i], tt);
                }
                else
                {
                    tt += btime[i];
                    btime[i] = 0;
                    printf("\nP%d\t\t%d\t\t%d", i, btime[i], tt);
                }
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}