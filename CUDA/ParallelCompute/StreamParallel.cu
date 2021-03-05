/**
 * Description: 流并行
 * Author: Bao Wenjie
 * Date: 2021/3/5
 * REF: https://blog.csdn.net/Augusdi/article/details/12833235?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.control&dist_request_id=&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.control
 */

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <iostream>
using namespace ::std;

cudaError_t addWithCuda(int* c, const int* a, const int* b, size_t size);

__global__ void addKernel(int* c, const int* a, const int* b)
{
    int i = blockIdx.x;
    c[i] = a[i] + b[i];
}

int main()
{
    const int arraySize = 5;
    int a[arraySize], b[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        a[i] = rand();
        b[i] = rand();
    }
    int c[arraySize] = { 0 };

    // 保存返回的计算状态
    cudaError_t cudaStatus;
    cudaStatus = addWithCuda(c, a, b, arraySize);
    if (cudaStatus != cudaSuccess)
    {
        fprintf(stderr, "addWithCuda failed!");
        return 1;
    }
	// 输出结果
    for (int i = 0; i < arraySize; i++)
        cout << a[i] << " ";
    cout << endl;
    for (int i = 0; i < arraySize; i++)
        cout << b[i] << " ";
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

	// 声明流
    cudaStream_t stream[5];
    for (int i = 0; i < 5; i++)
    {
        //创建流
        cudaStreamCreate(&stream[i]);
    }

	for (int i = 0; i < 5; i++)
    {
		// <<< 块数, 块中的线程数, 共享内存大小, 流对象 >>>
        addKernel << <1, 1, 0, stream[i] >> > (dev_c + i, dev_a + i, dev_b + i);	//执行流
    }

	// 流同步
    cudaStatus = cudaDeviceSynchronize();
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
    for (int i = 0; i < 5; i++)
    {
        //销毁流
        cudaStreamDestroy(stream[i]);
    }
	cudaFree(dev_c);
    cudaFree(dev_a);
    cudaFree(dev_b);
    return cudaStatus;
}