# 最小费用最大流的 Busacker Gowan算法

### 简介：

给定图$G=(V,E,C)$，和起点$s$、终点$t$，在$s\to t$的最大流$f$中求一个流，使其费用最低。



### 算法流程：

~~~
1. 初始化graph[当前图中的流量]=0，cost_graph_tmp[当前图中各边的费用]；

2. 利用SPFA算法求得cost_graph_tmp中s->t的最短路径，用path记录父节点；

3. 用path回溯，更新图流量graph(正向边相加，负向边相减)，更新cost_graph_tmp(如果边流量到达最大流量设为INF)；

4. 重复2-3直到不存在最短正路径;

5.返回graph。
~~~

