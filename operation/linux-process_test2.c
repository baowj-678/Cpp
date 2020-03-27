#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(void)
{
    pid_t pid;
    pid = fork();
    if(pid == 0)
        printf("Hello World!\n");
    else if(pid > 0)
        printf("How are you!\npid=%d\n", pid);
    return 0;
}