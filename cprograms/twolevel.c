#include <stdio.h>

struct st
{
    char dname[10];
    char sdname[10][10];
    char fname[10][10][10];
    int ds, sds[10];
} dir[10];

int main()
{
    int i, j, k, n;
    printf("Enter the number of directories: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter directory %d name: ", i + 1);
        scanf("%s", dir[i].dname);

        printf("Enter size of directory %d: ", i + 1);
        scanf("%d", &dir[i].ds);

        for (j = 0; j < dir[i].ds; j++)
        {
            printf("Enter subdirectory name and size: ");
            scanf("%s", dir[i].sdname[j]);
            scanf("%d", &dir[i].sds[j]);

            for (k = 0; k < dir[i].sds[j]; k++)
            {
                printf("Enter file name: ");
                scanf("%s", dir[i].fname[j][k]);
            }
        }
    }

    printf("\n");
    printf("\ndirname\t\tsize\tsubdirname\tsize\tfiles");
    printf("\n******************************************************\n");

    for (i = 0; i < n; i++)
    {
        printf("%30s\t\t%d", dir[i].dname, dir[i].ds);

        for (j = 0; j < dir[i].ds; j++)
        {
            printf("\t%30s\t\t%d\t", dir[i].sdname[j], dir[i].sds[j]);

            for (k = 0; k < dir[i].sds[j]; k++)
                printf("%30s\n\t\t\t\t\t\t\t", dir[i].fname[j][k]);

            printf("\n");
        }
    }

    return 0;
}
