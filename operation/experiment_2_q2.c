#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <sys/select.h>

void *A(void* args)
{
    int i = 1;
    struct timeval timeout;
    timeout.tv_usec = 500,000,000;
    timeout.tv_sec = 1;
    while(i <= 1000)
    {
        printf("A:%d  ", i++);
        select(0, NULL, NULL, NULL, &timeout);
    }
    return NULL;
}

void* B(void* args)
{
    int i = 1000;
    struct timeval timeout;
    timeout.tv_usec = 500,000,000;
    timeout.tv_sec = 1;
    while(i > 0)
    {
        printf("B:%d  ", i--);
        select(0, NULL, NULL, NULL, &timeout);
    }
    return NULL;
}


int main()
{
    printf("hello\n");
    pthread_t thread_A, thread_B;
    int i = 0;
    // for(i=0;i<9;i++)
    // {
    //     printf("i\n");
        usleep(500000);
    // }
    pthread_create(&thread_A, NULL, A, NULL);
    pthread_join(thread_A, NULL);
    pthread_create(&thread_B, NULL, B, NULL);
    pthread_join(thread_B, NULL);
    
    return 0;
}