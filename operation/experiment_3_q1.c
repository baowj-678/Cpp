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
    char number;
};

void handler_kill(int signum)
{
    exit(0);
}

void handler_print(int signum)
{
    key_t key = ftok(".", 5);
	int shmid = shmget(key, 0, 0);//通过ftok函数得到id值存在key中
	void *pshm = shmat(shmid, 0, 0);//挂接操作，成功返回指向共享存储段的指针，出错返回-1
    if (*(int *)pshm == -1) {//查看挂接是否成功如果出错返回-1，报错
		printf("shmat error!\n");
		exit(0);
	}
    struct Msg * msg = (struct Msg*)pshm;
    if(msg->is_empty == 0)
    {
        printf("%d\n", msg->number);
        msg->is_empty = 1;
    }
}
int main()
{
    void *pshm;
    key_t key = ftok(".", 5);
    int shmid = shmget(key, sizeof(struct Msg), 0666 | IPC_CREAT);
    pshm = shmat(shmid, 0, 0);
    if (*(int *)pshm == -1) {   //查看挂接是否成功如果出错返回-1，报错
		printf("shmat error!\n");
		exit(0);
	}
    struct Msg *msg = (struct Msg *)pshm;
    msg->is_empty = 1;
    pid_t pid;
    signal(SIGUSR1, handler_print);
    signal(SIGUSR2, handler_kill);
    pid = fork();
    //parent process
    if(pid != 0)
    {
        int i;
        for(i = 1; i <= 100; i++)
        {
            if(msg->is_empty != 0)
            {
                msg->number = i;
                msg->is_empty = 0;
                raise(SIGUSR1);
                usleep(100000);
            }
            if(i == 100)
            {
                kill(pid, SIGUSR2);
                sleep(1);
            }
        }
    }
    //subprocess
    if(pid == 0)
    {
        sleep(100);
    }
    return 0;
}