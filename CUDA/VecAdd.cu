/**
 * Description: 利用GPU实现向量加法
 * Author: Bao Wenjie
 * Date: 2021/3/3
 * REF: https://blog.csdn.net/xierhacker/article/details/52473747?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-3.control&dist_request_id=&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-3.control
 */

#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <iostream>

using namespace ::std;
const int maxn = 10;

__global__ void kernel_add(int* a, int* b, int* res)
{
	res[blockIdx.x] = a[blockIdx.x] + b[blockIdx.x];
}

int main()
{
	int res[maxn], a[maxn], b[maxn];
	// 设备内存地址
	int* dev_res, * dev_a, * dev_b;

	for (int i = 0; i < maxn; i++)
		a[i] = b[i] = rand();
	// 分配GPU空间
	cudaMalloc((void**)&dev_res, maxn * sizeof(int));
	cudaMalloc((void**)&dev_a, maxn * sizeof(int));
	cudaMalloc((void**)&dev_b, maxn * sizeof(int));

	// 将主机数据复制到设备
	cudaMemcpy(dev_a, a, maxn * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(dev_b, b, maxn * sizeof(int), cudaMemcpyHostToDevice);

	// 调用核函数
	kernel_add << <maxn, 1 >> > (dev_a, dev_b, dev_res);

	// 将设备数据复制到主机
	cudaMemcpy(res, dev_res, maxn * sizeof(int), cudaMemcpyDeviceToHost);

	// 释放空间
	cudaFree(dev_a);
	cudaFree(dev_b);
	cudaFree(dev_res);

	for(int i = 0; i < maxn; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < maxn; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < maxn; i++)
	{
		cout << res[i] << " ";
	}
	return 0;
}