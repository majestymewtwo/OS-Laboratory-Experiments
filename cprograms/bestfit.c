#include <stdio.h>

void main()
{
    int a[20], p[20], i, j, n, m, temp, b[20], temp1, temp2, c[20];
    printf("\nMEMORY MANAGEMENT SCHEME - BEST FIT\n");
    printf("Enter No. of Blocks: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the %dth block size: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("Enter No. of Processes: ");
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        printf("Enter the size of %dth process: ", i + 1);
        scanf("%d", &p[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = i + 1; j < m; j++)
        {
            if (p[i] > p[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    printf("\nProcess\tBlock Size\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\n", p[i], a[i]);
    }
    printf("\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (p[j] <= a[i])
            {
                printf("\nThe process %d [size %d] is allocated to block %d\n", j, p[j], a[i]);
                p[j] = 10000;
                break;
            }
        }
    }
    for (j = 0; j < m; j++)
    {
        if (p[j] != 10000)
        {
            printf("\nThe process %d is not allocated\n", p[j]);
        }
    }
}
