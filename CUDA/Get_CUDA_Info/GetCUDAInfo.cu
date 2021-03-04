/**
 * Description: 获取CUDA属性
 * Author: Bao Wenjie
 * Date: 2021/3/4
 */

#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <iostream>

using namespace ::std;


int main()
{
	cudaError_t cudaStatus;
	int num = 0;
	cudaStatus = cudaGetDeviceCount(&num);
	cout << "共有：" << num << "块 GPU" << endl << endl;
	cudaDeviceProp prop;
	for (int i = 0; i < num; i++)
	{
		cudaGetDeviceProperties(&prop, i);
		cout << "第" << i << "块 GPU" << endl;
		cout << "GPU名称: " << prop.name << endl;
		cout << "显存大小为: " << prop.totalGlobalMem << endl;
		cout << "版本号: " << prop.major << "." << prop.minor << endl;
		cout << "GPU大核数: " << prop.multiProcessorCount << endl;
	}
	
}