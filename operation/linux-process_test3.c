#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
void int_handler(int signum)
{
    printf("\nBye Bye!\n");
    exit(-1);
}
int main(void)
{
    signal(SIGINT, int_handler);
    printf("int_handler set for SIGINT\n");
    
    while(1)
    {
        printf("go to sleep!\n");
        sleep(1);
    }
    return 0;
}