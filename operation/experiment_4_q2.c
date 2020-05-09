#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>
#include <sys/wait.h>

void mem_addr(unsigned long vaddr, unsigned long* paddr)
{
    int pageSize = getpagesize(); //调用此函数获取系统设定的页面大小
    printf("页面大小为%d\n", pageSize);

    unsigned long v_pageIndex = vaddr / pageSize; //计算此虚拟地址相对于0x0的经过的页面数
    printf("页面数为：%u\n", v_pageIndex);
    unsigned long v_offset = v_pageIndex * sizeof(uint64_t); //计算在/proc/pid/page_map文件中的偏移量
    unsigned long page_offset = vaddr % pageSize;            //计算虚拟地址在页面中的偏移量
    printf("偏移量为：%x\n", page_offset);
    uint64_t item = 0;                             //存储对应项的值
    int fd = open("/proc/self/pagemap", O_RDONLY); //以只读方式打开/proc/pid/page_map

    lseek(fd, v_offset, SEEK_SET);                         //将游标移动到相应位置，即对应项的起始地址且判断是否移动失败
    read(fd, &item, sizeof(uint64_t)) != sizeof(uint64_t); //读取对应项的值，并存入item中，且判断读取数据位数是否正确

    if ((((uint64_t)1 << 63) & item) == 0) //判断present是否为0
    {
        printf("page present is 0\n");
        return;
    }
    printf("物理页号为%u\n", ((uint64_t)1 << 63) & item);
    uint64_t phy_pageIndex = (((uint64_t)1 << 55) - 1) & item; //计算物理页号，即取item的bit0-54
    printf("物理页号为%u\n", item);
    *paddr = (phy_pageIndex * pageSize) + page_offset; //再加上页内偏移量就得到了物理地址
}

const int a = 100; //全局常量
int main()
{
    unsigned long phy = 0; //物理地址

    mem_addr((unsigned long)&a, &phy);
    printf("进程id为 = %d, 虚拟地址为 = %x , 物理地址为 = %x\n", getpid(), &a, phy);
    sleep(10);
    //waitpid();
    return 0;
}