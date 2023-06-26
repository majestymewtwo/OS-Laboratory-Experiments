#include <stdio.h>
#include <time.h>
int fib(int);
// Defining the fork() and sleep() function to avoid implicit declaration warning
int fork(void);
void sleep(unsigned);

void main()
{
    int begin = time(NULL); // Returns current time in seconds since UNIX epoch (Jan 1, 1970)
    int i;
    if (fork() == 0)
        for (i = 0; i < 10; i++)
            printf("Fibonacci series member(%2d)=%d\n", i + 1, fib(i));
    else
        for (i = 0; i < 10; i++)
        {
            sleep(2); // Pauses the execution of the current process for 2s
            printf("Elapsed time=%td\n", time(NULL) - begin);
        }
}

int fib(int n)
{
    if (n <= 1)
        return n;
    else
        return (fib(n - 1) + fib(n - 2));
}