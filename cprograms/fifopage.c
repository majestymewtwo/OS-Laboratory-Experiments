#include <stdio.h>

int main()
{
    int n, i, j, a[50], frame[10], no, k, avail, count = 0;

    printf("\nEnter the number of pages: ");
    scanf("%d", &n);

    printf("\nEnter the page numbers: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nEnter the number of frames: ");
    scanf("%d", &no);

    for (i = 0; i < no; i++)
        frame[i] = -1;

    j = 0;

    printf("\nReference string\tPage frames\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t\t", a[i]);
        avail = 0;

        for (k = 0; k < no; k++)
        {
            if (frame[k] == a[i])
                avail = 1;
        }

        if (avail == 0)
        {
            frame[j] = a[i];
            j = (j + 1) % no;
            count++;

            for (k = 0; k < no; k++)
                printf("%d\t", frame[k]);
        }

        printf("\n");
    }

    printf("\nPage fault: %d\n", count);

    return 0;
}
