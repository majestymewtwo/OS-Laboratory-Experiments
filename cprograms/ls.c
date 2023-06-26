#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct dirent **namelist;
    int n, i;
    char pathname[100];
    getcwd(pathname, sizeof(pathname)); // Stores the current working direcory name in the pathname variable buffer
    n = scandir(pathname, &namelist, 0, alphasort);
    if (n < 0)
        printf("\nError\n");
    else
    {
        for (i = 0; i < n; i++)
            printf("%s\n", namelist[i]->d_name);
    }
}