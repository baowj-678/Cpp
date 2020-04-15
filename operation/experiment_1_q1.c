#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{
    pid_t pid = 0;
    pid = fork();
    if(pid == 0)
    {
        printf("parent process: pid=%d\n", pid);
    }
    else
    {
        printf("subprocess: pid=%d\n",pid);
    }
    return 0;
}