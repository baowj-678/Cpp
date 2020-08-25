# 快速幂

### 算法简介：

**分解**：

$$index=2^0a_0+2^1a_1+2^2a_2+\cdots 2^na_n\quad for \ a_i\in\{0, 1\}$$

$$base^{index}=base^{2^0a_0}\cdot base^{2^1a_1}\cdot base^{2^2a_2}\cdots base^{2^na_n}$$

**又**：

$$base^{2^i}={base^{2^{i-1}}}^2$$



### 算法时间复杂度：

$$\Theta(\log(index))\quad for\ base^{index}$$