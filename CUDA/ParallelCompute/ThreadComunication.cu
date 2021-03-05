/**
 * Description: 线程并行
 * Author: Bao Wenjie
 * Date: 2021/3/5
 * REF: https://blog.csdn.net/Augusdi/article/details/12833235?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.control&dist_request_id=&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.control
 */

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "device_functions.h"
#include <iostream>
using namespace ::std;

cudaError_t addWithCuda(int* c, const int* a, size_t size);

__global__ void addKernel(int* c, const int* a)
{
    int i = threadIdx.x;
    extern __shared__ int smem[];
    smem[i] = a[i];
    __syncthreads();
    // 0号线程做平方和
    if (i == 0)
    {
        c[0] = 0;
        for (int d = 0; d < 5; d++)
        {
            c[0] += smem[d] * smem[d];
        }
    }
    //1号线程做累加
    if (i == 1)
    {
        c[1] = 0;
        for (int d = 0; d < 5; d++)
        {
            c[1] += smem[d];
        }
    }
    //2号线程做累乘
    if (i == 2)
    {
        c[2] = 1;
        for (int d = 0; d < 5; d++)
        {
            c[2] *= smem[d];
        }
    }
}


int main()
{
    const int arraySize = 5;
    int a[arraySize];
    for (int i = 0; i < arraySize; i++)
        a[i] = rand();
    int c[arraySize] = { 0 };

	// 计算
    cudaError_t cudaStatus = addWithCuda(c, a, arraySize);
    if (cudaStatus != cudaSuccess)
    {
        fprintf(stderr, "addWithCuda failed!");
        return 1;
    }

	// 打印计算结果
    for (int i = 0; i < arraySize; i++)
        cout << a[i] << " ";
    cout << endl;
    for (int i = 0; i < arraySize; i++)
        cout << c[i] << " ";
    cout << endl;
	
    cudaStatus = cudaThreadExit();
    if (cudaStatus != cudaSuccess)
    {
        fprintf(stderr, "cudaThreadExit failed!");
        return 1;
    }
    return 0;
}


cudaError_t addWithCuda(int* c, const int* a, size_t size)
{
    int* dev_a = 0;
    int* dev_c = 0;
    cudaError_t cudaStatus;

	// 选择GPU设备
    cudaStatus = cudaSetDevice(0);
    if (cudaStatus != cudaSuccess)
    {
        fprintf(stderr, "cudaSetDevice failed!  Do you have a CUDA-capable GPU installed?");
        goto Error;
    }

	// 获取显存
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

	// 将主机数据拷贝到设备
    cudaStatus = cudaMemcpy(dev_a, a, size * sizeof(int), cudaMemcpyHostToDevice);
    if (cudaStatus != cudaSuccess)
    {
        fprintf(stderr, "cudaMemcpy failed!");
        goto Error;
    }

	// 调用kernel函数
    addKernel << <1, size, size * sizeof(int), 0 >> > (dev_c, dev_a);
	// 线程同步
    cudaStatus = cudaDeviceSynchronize();
    if (cudaStatus != cudaSuccess)
    {
        fprintf(stderr, "cudaThreadSynchronize returned error code %d after launching addKernel!\n", cudaStatus);
        goto Error;
    }

	// 将数据从设备拷贝到主机
    cudaStatus = cudaMemcpy(c, dev_c, size * sizeof(int), cudaMemcpyDeviceToHost);
    if (cudaStatus != cudaSuccess)
    {
        fprintf(stderr, "cudaMemcpy failed!");
        goto Error;
    }

Error:
    cudaFree(dev_c);
    cudaFree(dev_a);
    return cudaStatus;
}