#include <stdio.h>

int main()
{
    int master, s[20];
    char f[20][20][20];
    char d[20][20];
    int i, j;

    printf("Enter the number of directories: ");
    scanf("%d", &master);

    printf("Enter names of directories: ");
    for (i = 0; i < master; i++)
        scanf("%s", d[i]);

    printf("Enter size of directories: ");
    for (i = 0; i < master; i++)
        scanf("%d", &s[i]);

    printf("Enter the filenames: ");
    for (i = 0; i < master; i++)
    {
        for (j = 0; j < s[i]; j++)
            scanf("%s", f[i][j]);
    }

    printf("\n");
    printf("Directory \t Size \t Files\n");
    printf("\n");

    for (i = 0; i < master; i++)
    {
        printf("%s \t\t %2d \t", d[i], s[i]);

        for (j = 0; j < s[i]; j++)
            printf("%s  ", f[i][j]);

        printf("\n");
    }

    printf("\n");

    return 0;
}
