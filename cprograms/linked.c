#include <stdio.h>

struct block
{
    int p_id;
    int b_allocated;
    struct block *next;
};

struct block b[50];
struct block *sblock = NULL;
int n;

void display();

int main()
{
    int i, pname, psize, no, bname, freespace = 0, count, previous;

    printf("\nEnter the number of blocks: ");
    scanf("%d", &n);
    freespace = n;

    for (i = 0; i < n; i++)
    {
        b[i].p_id = 0;
        b[i].b_allocated = 0;
    }

    printf("\nEnter the number of blocks already allocated: ");
    scanf("%d", &no);

    for (i = 0; i < no; i++)
    {
        printf("\nEnter the allocated block: ");
        scanf("%d", &bname);
        b[bname].p_id = 100;
        b[bname].b_allocated = 1;
        freespace = freespace - 1;
    }

    display();

    printf("\nEnter process name: ");
    scanf("%d", &pname);

    printf("\nEnter process size: ");
    scanf("%d", &psize);

    count = 0;

    if (psize <= freespace)
    {
        for (i = 0; i < n; i++)
        {
            if (b[i].b_allocated == 0)
            {
                b[i].b_allocated = 1;
                b[i].p_id = pname;
                count++;

                if (count == 1)
                    sblock = &b[i];
                else if (count > psize)
                    break;
                else
                    b[previous].next = &b[i];

                previous = i;
            }
        }

        display();
        printf("\nProcess name: %d\nStarting address: %p\nEnding address: %p", pname, sblock, &b[i]);
    }
    else
    {
        printf("\nProcess cannot be allocated");
    }

    return 0;
}

void display()
{
    int i, count = 0;

    printf("\nBlocks\n");

    for (i = 0; i < n; i++)
    {
        if (count < 2)
        {
            printf("%p-->\tb[%2d]->\t%2d->\t%2d->\t%4p\t\t", &b[i], i, b[i].p_id, b[i].b_allocated, b[i].next);
        }
        else
        {
            count = 0;
            printf("\n%p-->\tb[%2d]->\t%2d->\t%2d->\t%4p\t\t", &b[i], i, b[i].p_id, b[i].b_allocated, b[i].next);
        }

        count = count + 1;
    }
}
