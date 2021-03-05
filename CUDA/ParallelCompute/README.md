# CUDA多线程并行计算

### 线程并行

#### 简介

GPU上线程**没有优先级**概念，所有线程机会均等，线程状态只有**等待资源**和**执行**两种状态，如果资源未就绪，那么就等待；一旦就绪，立即执行。

当GPU资源很充裕时，所有线程都是**并发执行**的，这样加速效果很接近理论加速比；

当GPU资源少于总线程个数时，有一部分线程就会等待前面执行的线程释放资源，从而变为**串行化执行**。



### 流并行

#### 简介

**流并行**，可以执行不同的核函数，也可以实现对同一个核函数传递不同的参数，实现任务级别的并行



### API

* **cudaThreadSynchronize**：【无参函数】*Its functionality is similar to the non-deprecated function **cudaDeviceSynchronize()**, which should be used instead.*
* **cudaDeviceSynchronize**：【无参函数】**停止CPU**端线程的执行，直到GPU端完成之前CUDA的任务，包括kernel函数、数据拷贝等；
* **cudaStreamSynchronize**：这个方法接受一个stream ID，它将**阻止CPU执行**直到GPU端完成相应stream ID的所有CUDA任务，但其它stream中的CUDA任务可能执行完也可能没有执行完；
* **cudaStreamCreate(cudaStream_t * s)**：创建流；
* **cudaStreamDestroy(cudaStream_t s)**：销毁流；
* **cudaStreamSynchronize()**：流同步；
* **cudaStreamQuery()**：查询一个流的任务是否完成；
* **\_\_syncthreads()**：CUDA的内建函数，用于块内线程通信；保证**block**内的所有线程都已经运行到调用__syncthreads()的位置，这样可以保证各个线程看到的存储器是一样的；