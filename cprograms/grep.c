#include <stdio.h>
#include <string.h>

void print();

int count = 0, notfound = 1, flag = 0, linec = 1;
char line[50] = "";

int main()
{
    FILE *fp;
    char ch, filename[100], s[50], line[50];
    int n, i;
    printf("Enter filename : ");
    scanf("%[^\n]", filename); // Gets file name from user eg: new.txt
    fp = fopen(filename, "r"); // Opens the file in
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return -1;
    }
    printf("\nEnter the sequence: ");
    scanf("%s", s);
    n = strlen(s);

    while (1)
    {
        ch = fgetc(fp); // Gets each character from the file stream

        if (ch == '\n' && flag == 1) // If end of line is reached and flag is 1, it means there is a mathc for the sequence in that current line
        {
            print();
        }

        if (ch == s[count]) // If one character matches, increase the count variable
        {
            count = count + 1;

            if (count == n) // If count has reached n, it means sequence is fully matched so we set flag = 1
            {
                flag = 1;
            }
        }
        else if (ch == EOF) // End of file requires exit from while loop
        {
            break;
        }
        else if (ch == '\n') // End of line reached with no match in pattern
        {
            linec = linec + 1; // Keeping track of the lines
        }
        else if (ch != s[count]) // If no match setting the count variable back to 0
        {
            count = 0;
        }
    }
    fclose(fp);

    if (notfound == 1)
    {
        printf("\nSequence not found in the line\n");
    }

    return 0;
}

void print()
{
    int i;
    printf("\nSequence found in the line %d\n", linec);
    linec++;
    flag = 0;
    notfound = 0;
    count = 0;
}
