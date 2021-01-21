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

