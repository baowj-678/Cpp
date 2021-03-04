/**
 * Description: 利用GPU实现加法
 * Author: Bao Wenjie
 * Date: 2021/3/3
 * REF: https://blog.csdn.net/xierhacker/article/details/52473747?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-3.control&dist_request_id=&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-3.control
 */
#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <cstdio>

using namespace ::std;
__global__ void add(int a, int b, int* c)
{
	*c = a + b;
}

int main()
{
	int c;
	int a = 1;
	int b = 7;
	int* dev_c;
	// 在GPU上分配内存
	cudaMalloc((void**)&dev_c, sizeof(int));
	// 将计算结果存入dev
	add << <1, 1 >> > (a, b, dev_c);
	// 将GPU内容复制到主机
	cudaMemcpy(&c, dev_c, sizeof(int), cudaMemcpyDeviceToHost);
	// 释放GPU内存
	cudaFree(dev_c);
	printf("%d + %d = %d\n", a, b, c);
	return 0;
}