/**
 * Description: 线程并行
 * Author: Bao Wenjie
 * Date: 2021/3/4
 * REF: https://blog.csdn.net/Augusdi/article/details/12833235?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.control&dist_request_id=&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.control
 */

#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <iostream>

using namespace ::std;

cudaError_t addWithCuda(int* c, const int* a, const int* b, size_t size);

// kernel函数
__global__ void addKernel(int* c, const int* a, const int* b)
{
    int i = threadIdx.x;
    c[i] = a[i] + b[i];
}

int main()
{
    const int arraySize = 5;
    const int a[arraySize] = { 1, 2, 3, 4, 5 };
    const int b[arraySize] = { 10, 20, 30, 40, 50 };
    int c[arraySize] = { 0 };

	// 保存返回的计算状态
    cudaError_t cudaStatus;
    cudaStatus = addWithCuda(c, a, b, arraySize);
    if (cudaStatus != cudaSuccess)
    {
        fprintf(stderr, "addWithCuda failed!");
        return 1;
    }
	
    cudaStatus = cudaThreadExit();
	
    if (cudaStatus != cudaSuccess)
    {
        fprintf(stderr, "cudaThreadExit failed!");
        return 1;
    }
    return 0;
}


cudaError_t addWithCuda(int* c, const int* a, const int* b, size_t size)
{
    int* dev_a = 0;
    int* dev_b = 0;
    int* dev_c = 0;
	
    cudaError_t cudaStatus;

	// 选择运行的设备(GPU)
    cudaStatus = cudaSetDevice(0);
    if (cudaStatus != cudaSuccess)
    {
        fprintf(stderr, "cudaSetDevice failed!  Do you have a CUDA-capable GPU installed?");
        goto Error;
    }
	
    // 分配GPU设备端内存
    cudaStatus = cudaMalloc((void**)&dev_c, size * sizeof(int));
    if (cudaStatus != cudaSuccess)
    {
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }
    cudaStatus = cudaMalloc((void**)&dev_a, size * sizeof(int));
    if (cudaStatus != cudaSuccess)
    {
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }
    cudaStatus = cudaMalloc((void**)&dev_b, size * sizeof(int));
    if (cudaStatus != cudaSuccess)
    {
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }
	
    // 拷贝数据到GPU
    cudaStatus = cudaMemcpy(dev_a, a, size * sizeof(int), cudaMemcpyHostToDevice);
    if (cudaStatus != cudaSuccess)
    {
        fprintf(stderr, "cudaMemcpy failed!");
        goto Error;
    }
    cudaStatus = cudaMemcpy(dev_b, b, size * sizeof(int), cudaMemcpyHostToDevice);
    if (cudaStatus != cudaSuccess)
    {
        fprintf(stderr, "cudaMemcpy failed!");
        goto Error;
    }
	
    // 运行核函数
	addKernel <<< 1, size >>> (dev_c, dev_a, dev_b);
	cudaStatus = cudaThreadSynchronize();	//同步线程
    if (cudaStatus != cudaSuccess)
    {
        fprintf(stderr, "cudaThreadSynchronize returned error code %d after launching addKernel!\n", cudaStatus);
        goto Error;
    }
	// 将GPU数据拷贝回CPU
    cudaStatus = cudaMemcpy(c, dev_c, size * sizeof(int), cudaMemcpyDeviceToHost);
    if (cudaStatus != cudaSuccess)
    {
        fprintf(stderr, "cudaMemcpy failed!");
        goto Error;
    }
	
Error:
    cudaFree(dev_c);	//释放GPU设备端内存
    cudaFree(dev_a);
    cudaFree(dev_b);
    return cudaStatus;
}