#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>


struct Msg
{
    char is_empty;
    char in[100];
};

int sum = 0;

void handler_print(int signum)
{
    key_t key = ftok(".", 5);
	int shmid = shmget(key, 0, 0);
	void *pshm = shmat(shmid, 0, 0);
    if (*(int *)pshm == -1) {
		printf("shmat error!\n");
		exit(0);
	}
    struct Msg * msg = (struct Msg*)pshm;
    if(msg->is_empty == 0)
    {
        int number = atoi(msg->in);
        if(number == 0)
            printf("%s\n", msg->in);
        else
            printf("%d\n", sum += number);
        msg->is_empty = 1;
    }
    if(sum >= 100)
    {
        printf("My work done!\n");
        exit(0);
    }
}

int main()
{
    void *pshm;
    key_t key = ftok(".", 5);
    int shmid = shmget(key, sizeof(struct Msg), 0666 | IPC_CREAT);
    pshm = shmat(shmid, 0, 0);
    if (*(int *)pshm == -1) {
		printf("shmat error!\n");
		exit(0);
	}
    struct Msg *msg = (struct Msg *)pshm;
    msg->is_empty = 1;
    pid_t pid;
    signal(SIGUSR1, handler_print);
    pid = fork();
    //parent process
    if(pid != 0)
    {
        int i;
        while(1)
        {
            if(msg->is_empty != 0)
            {
                printf("please input:\n");
                scanf("%s", msg->in);
                msg->is_empty = 0;
                raise(SIGUSR1);
                usleep(100);
            }
        }
    }
    //subprocess
    if(pid == 0)
    {
        int sum = 0;
        wait(NULL);
    }
    return 0;
}