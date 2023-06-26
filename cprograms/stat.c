#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
struct stat nfile;
int main(int argc, char *argv[])
{
    char fname[20];
    printf("Enter the filename: ");
    scanf("%s", fname);
    stat(fname, &nfile); //This function is used to obtain information about a given file in the current directory, if it does not exist it will return -1
    int flag;
    flag = stat(fname, &nfile);
    if (flag == -1)
    {
        errno = ENOENT; //No file or directory error code
        perror("An error has occured"); //Throw error message
    }
    else
    {
        printf("File Exists and Filename is given\n");
        printf("The information about the file %s\n\n", fname);
        printf("%s has %lu link\n", fname, nfile.st_nlink); //st_nlink means the number of hard links (aliases) pointing to the same file
        printf("%s has %lu as device ID\n", fname, nfile.st_dev); //st_dev returns the device ID of the current operating system where file is stored
        printf("%s has %lu inodes\n", fname, nfile.st_ino); //st_inode means the number of inodes of the current file, inode are data structures that store metadata about the given file
        printf("%s has %lu inode devices\n", fname, nfile.st_rdev); //st_rdev holds the device ID of the special file
        printf("%s has %lu bytes size\n", fname, nfile.st_size);//st_size returns the size of the file in bytes
        printf("%s has %u owner\n", fname, nfile.st_gid);//st_gid holds the group ID of the owner
        printf("%s has %lu access time\n", fname, nfile.st_atime);//st_atime holds last access time of file since UNIX epoch (Jan 1, 1970)
        printf("%s has %lu modification time\n", fname, nfile.st_mtime); // st_mtime holds last modification time of file since UNIX epoch (Jan 1, 1970)
    }
}