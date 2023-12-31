#include <stdio.h>
void interchange(int *, int *);
// s[] for service times
// p[] for priorities
void main()
{
    int s[25], p[25], n, j, i, wt = 0, swt = 0, tt = 0, stt = 0;
    printf("\nPRIORITY SCHEDULING PROCESS\n");
    printf("Enter the no. of jobs:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nService Time or Burst Time for a process %d: ", i);
        scanf("%d", &s[i]);
        printf("\nEnter the Priority %d: ", i);
        scanf("%d", &p[i]);
    }
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurn Around Time");
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i] < p[j])
            {
                interchange(&s[i], &s[j]); // Switching Service Time Array
                interchange(&p[i], &p[j]); // Switching Priority Array
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        swt = swt + wt;
        tt = tt + s[i];
        stt = stt + tt;
        printf("\nP%d\t%d\t\t%d\t\t%d\t\t\t%d", i, s[i], p[i], wt, tt);
        wt = wt + s[i];
    }
    printf("\n\n\tAverage Waiting Time=%d", swt / n);
    printf("\n\n\tAverage Turn Around Time=%d\n", stt / n);
}
void interchange(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
