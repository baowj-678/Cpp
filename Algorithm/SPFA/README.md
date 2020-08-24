# SPFA(单源最短路算法)

### 简介：

**Shortest Path Faster Algorithm**，是 **Bellman-Ford算法**的队列优化算法的别称，通常用于求含负权边的单源最短路径，以及判负权环。

**优点**：

* 最坏情况时间复杂为O(VE)
* 可以计算**负权图**
* 能够判断**负环**



### 算法：

数组**d**：记录每个结点的最短路径估计值；

邻接表**G**：存储图；

**FIFO**(先进先出)队列**Q**：保存待优化的结点。

**流程**

~~~
1. 取出Q队首节点u；

2. 利用u点当前的最短路径估计值d[u]，以及G[u, v]对所有的v进行松弛操作；

3. 如果v点的最短路径估计值d[v]发生改变，且v不在当前队列中，将v放入队尾；

4. 直到队列为空。

5. 如果某个结点出队超过n次，可判定存在负环
~~~
