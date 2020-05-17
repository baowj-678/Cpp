#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>
#include <sys/wait.h>

void mem_addr(unsigned long vaddr, unsigned long *paddr)
{
     //调用此函数获取系统设定的页面大小
    int pageSize = getpagesize();
    //计算此虚拟地址相对于0x0的经过的页面数
    unsigned long v_pageIndex = vaddr / pageSize; 
    printf("虚拟页号为：%lu\n", v_pageIndex);
    //计算在/proc/pid/page_map文件中的偏移量
    unsigned long v_offset = v_pageIndex * sizeof(uint64_t); 
    //计算虚拟地址在页面中的偏移量
    unsigned long page_offset = vaddr % pageSize;            
    printf("页内偏移地址：%lx\n", page_offset);
    uint64_t item = 0;
    //以只读方式打开/proc/pid/page_map
    int fd = open("/proc/self/pagemap", O_RDONLY);
     if (fd<0)
    {
        printf("open /proc/self/pagemap failed\n");
        return;
    }


    lseek(fd, v_offset, SEEK_SET);                         
    //读取对应项的值，并存入item中，且判断读取数据位数是否正确
    read(fd, &item, sizeof(uint64_t)); 


    if ((((uint64_t)1 << 63) & item) == 0) //判断present是否为0
    {
        printf("page is not present\n");
        return;
    }
    //计算物理页号，即取item的bit0-54
    uint64_t phy_pageIndex = ((((uint64_t)1) << 55) - 1) & item; 
    printf("物理页框号为%lu\n", phy_pageIndex);
	//再加上页内偏移量就得到了物理地址
    *paddr = (phy_pageIndex * pageSize) + page_offset; 
}

const int a = 100; //全局常量
int main()
{
    unsigned long phy = 0; //物理地址

    printf("虚拟地址为 = %p\n", &a);
    mem_addr((unsigned long)&a, &phy);
    printf("物理地址为 = %lx\n", phy);
    sleep(10);
    //waitpid();
    return 0;
}