# 匈牙利算法(Hungarian Algorithm)

### 简介：

匈牙利算法是由匈牙利数学家Edmonds于1965年提出，因而得名。匈牙利算法是基于Hall定理中充分性证明的思想，它是部图匹配最常见的算法，该算法的核心就是寻找增广路径，它是一种用增广路径求**二分图最大匹配**的算法。



### 算法流程：

~~~
1. graph:邻接矩阵(0:未连接,1:可以连接);

2. 对graph中X部分结点u遍历:

3. 更改u状态为:已访问,对u所有未访问邻接结点v遍历:

4. 如果v结点未连接 -> 连接u-v,更改u、v状态为已连接,返回true;

5. 如果v结点已连接 -> u:=v转步骤3;

6. 更改u状态为:未访问,返回false;

7. 返回X的邻接表
~~~

