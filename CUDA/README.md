# CUDA编程

### 关键字:book:

* **__global__**：告诉系统,这个函数应该交给**编译设备代码的编译器**来编译；
* 



### CUDA常用函数

* **cudaMalloc**：在**设备(GPU)**上分配空间；

    \_\_host\_\_\_\_device\_\_cudaError\_t  cudaMalloc(void\*\***devPtr**, size\_t **size**)

    * **devPtr**：**主机(CPU)**一个指针变量的地址，存放分配好的空间地址；
    * **size**：需要分配空间的大小；

* **cudaMemcpy**：在**设备和设备**、**主机和设备**之间拷贝数据；

    \_\_host\_\_cudaError\_t cudaMemcpy (void \***dst**, const void \***src**, size\_t **count**, cudaMemcpyKind **kind**)

    *  **dst**：目的地址；
    * **src**：源地址；
    * **count**：拷贝空间大小；
    * **kind**：拷贝种类：
        * **cudaMemcpyHostToHost**：主机 -> 主机
        * **cudaMemcpyHostToDevice**：主机 -> 设备
        * **cudaMemcpyDeviceToHost**：设备 -> 主机
        * **cudaMemcpyDeviceToDevice**：设备 -> 设备

* **cudaFree**：释放**cudaMalloc**分配的空间；





### CUDA线程操作

* **gridDim.x**：线程网络X维度上线程块的数量
* **gridDim.y**：线程网络Y维度上线程块的数量
* **blockDim.x**：一个线程块X维度上的线程数量
* **blockDim.y**：一个线程块Y维度上的线程数量
* **blockIdx.x**：线程网络X维度上的线程块索引
* **blockIdx.y**：线程网络Y维度上的线程块索引
* **threadIdx.x**：线程块X维度上的线程索引
* **threadIdx.y**：线程块Y维度上的线程索引

**kernel**函数调用方法： **kernel<<<Dg, Db, Ns, S>>>()**

* **Dg**：定义整个**grid**的维度，类型是**Dim3**，但是实际上目前显卡支持两个维度，所以，**dim3<<Dg.x, Dg.y, 1>>>**第**z**维度默认只能为1；
* **Db**：定义了每个**block**的维度，类型**Dim3**，**dim3<<Db.x, Db.y, Db.z>>>**，三个维度的乘积有上限；
* **Ns**：是可选参数，设定最多能**动态分配的共享内存**大小，比如16k；当不需要时，这个值可以省略或写0；
* **S**：可选参数，表示流号，默认为0；

