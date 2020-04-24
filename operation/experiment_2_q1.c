#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>


int main()
{
    __pid_t pid;
    pid = fork();
    //parent process
    if(pid == 0)
    {
        printf("parent process,pid=%d\n", pid);
    }
    else
    {
        printf("subprocess,pid=%d\n", pid);
    }
    return 0;
}