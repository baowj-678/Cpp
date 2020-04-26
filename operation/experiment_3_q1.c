#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>

int number;
int is_empty = 1;

void handler_kill(int signum)
{
    exit(0);
}

void handler_print(int signum)
{
    // printf("hello");
    if(is_empty == 0)
    {
        printf("\n\n\n\n\n%d  ", number);
        is_empty = 1;
    }
}
int main()
{
    pid_t pid;
    pid = fork();
    //parent process
    if(pid != 0)
    {
        printf("parent");
        // int i;
        // for(i = 1; i <= 100; i++)
        // {
        //     if(is_empty != 0)
        //     {
        //         number = i;
        //         is_empty = 0;
        // kill(pid, SIGUSR1);
                // sleep(1);
        //     }
        //     if(i == 100)
        //     {
        //         kill(pid, SIGUSR2);
        //         sleep(10);
        //     }
        // }
        sleep(300);
        wait(NULL);
    }
    //subprocess
    if(pid == 0)
    {
        // signal(SIGUSR1, handler_print);
        // signal(SIGUSR2, handler_kill);
        printf("\nhello");
        int i = 0;
        for(; i < 100; i++)
        {
            printf("hello");
            sleep(1);
        }
        // int i=0;
        // for(;i<100;i++)
        // {}
    }
    return 0;
}