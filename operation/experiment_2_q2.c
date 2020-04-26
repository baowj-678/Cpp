#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/select.h>

void *A(void* args)
{
    int i = 1;
    while(i <= 1000)
    {
        printf("A:%d\n", i++);
        usleep(500000);
    }
    return NULL;
}

void* B(void* args)
{
    int i = 1000;
    while(i > 0)
    {
        printf("B:%d\n", i--);
        usleep(500000);
    }
    return NULL;
}


int main()
{
    printf("hello\n");
    pthread_t thread_A, thread_B;
    int i = 0;
    pthread_create(&thread_A, NULL, A, NULL);
    pthread_create(&thread_B, NULL, B, NULL);
    pthread_join(thread_A, NULL);
    pthread_join(thread_B, NULL);
    
    return 0;
}