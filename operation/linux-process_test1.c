#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(void)
{
    fork();
    printf("Hello World!\n");
    return 0;
}