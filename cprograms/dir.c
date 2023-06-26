#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

void main()
{
    DIR *dir;
    struct dirent *entry;
    int count;
    //opendir("/") means root directory
    //opendir(".") means current directory
    //opendir("..") means parent directory
    if ((dir = opendir(".")) == NULL){ //Returns the directory stream of specified directory if success, NULL if failed
        errno = EIO; //Setting error status as Input/Output error
        perror("opendir() error has occured"); //Printing the error with perror() statement
    }
        
    else
    {
        count = 0;
        while ((entry = readdir(dir)) != NULL) //Return the current directory and NULL if end of directory has reached
        {
            printf("Directory Entry %3d = %s \n", ++count, entry->d_name);
        }
        closedir(dir); //Closes the directory stream
    }
}