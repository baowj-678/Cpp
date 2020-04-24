#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// int main()
// {
//     int i;
//     for(i = 0; i < 10; i++)
//     {
//         printf("%d\n", i);
//         usleep(100000);
//     }
// }

void handler_ctrl_c(int n)
{
    printf("\nbye bye\n");
    exit(0);
}

int main()
{
    signal(SIGINT, handler_ctrl_c);
    while(1)
    {
        printf("hello\n");
        sleep(1);
    }
}