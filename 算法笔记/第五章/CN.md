# 组合数:zap:

## 计算组合数$C_n^m$

### 简介

**组合数公式**：

$C_n^m=\frac{n!}{m!(n-m)!}$



### 递推公式:dart:

$C_n^m=C_{n-1}^m+C_{n-1}^{m-1}$



### 定义变形:tractor:

$C_n^m=\frac{n!}{m!(n-m)!}=\frac{(n-m+1)(n-m+2)\dots(n-m+m)}{1\times2\times \dots \times m}$

$$=\frac{\frac{\frac{\frac{(n-m+1)}{1}\times(n-m+2)}{2}\times\dots}{\dots}\times(n-m+m)}{m}$$





## 计算$C_n^m\%p$

### Lucas定理

如果$p$是**素数**，将m，n表示为p进制：

$m=m_kp^k+m_{k-1}p^{k-1}+\dots+m_0$

$n=n_kp^k+n_{k-1}p^{k-1}+\dots+n_0$

则有：$C_n^m=C_{n_k}^{m_k}\times C_{n_{k-1}}^{m_{k-1}}\times\dots\times C_{n_0}^{m_0}(mod\bold{p})$