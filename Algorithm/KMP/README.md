# KMP

### 简介

**KMP(Knuth–Morris–Pratt string-searching algorithm)**，由 [James H. Morris](https://en.wikipedia.org/wiki/James_H._Morris) 、[Donald Knuth](https://en.wikipedia.org/wiki/Donald_Knuth)、[Vaughan Pratt](https://en.wikipedia.org/wiki/Vaughan_Pratt) 共同发明。主要用来查找字符串 `S` 中是否出现过字符串 `W`。其时间复杂度为 $$Θ(m+n)$$。



## 算法

### 算法分析

如下所示

```
m: 01234567890123456789012
S: ABC ABCDAB ABCDABCDABDE
W:     ABCDABD
i:     0123456
```

**ABCDAB**已经匹配成功，且其**最长后缀**，**AB**和**W**（**ABCDABD**）的对应前缀**AB**匹配。

因此后续步骤中不需要重新匹配**AB**，可以直接从**W[2]**开始匹配，如下图：

```
m: 01234567890123456789012
S: ABC ABCDAB ABCDABCDABDE
W:         ABCDABD
i:         0123456
```

所以，假设 **S[i]** 和 **W[j]** 不匹配（之前都匹配），**len**表示 **W[0 : j-1]** 的**最长后缀**和 **W** 匹配的长度；

则下一次其跳转的匹配位置为：**S[i+1]** 和 **W[len + 1]**。



#### Next数组计算

* Next[0] = 0；

* 对于第 **i + 1** 位置的Next值：

  * 如果 **W[Next[i]] = W[i]**，则 **Next[i + 1] = Next[i] +1**；【待证明1】

  * 否则，如果 **W[Next[Next[i]]] = W[Next[i]]**，则 **Next[i + 1] = Next[Next[i]] + 1**；【待证明2】

  * ###### …………

  * 否则，**Next[i + 1] = 0**；



##### 证明1

对于数组**W**，设 **Next[i] = k**；

有：W[0 : k-1] = W[i-k : i-1]；

又因为 **W[Next[i]] = W[i]**，即 **W[k] = W[i]**，所以有：W[0 : k] = W[i + k : i]；

所以：**Next[i + 1] = Next[i] +1**；



##### 证明2

对于数组**W**，设 **Next[i] = k**，有：W[0 : k-1] = W[i-k : i-1]；

对于 **Next[Next[i]]** 即 **Next[k]**，令**t = Next[k]**，且 **t < k**有：W[0 : t-1] = W[k-t : k-1]；

所以：W[0 : t-1] = W[k-t : k-1] = W[i-t : i-1]；

又因为：**W[Next[Next[i]]] = W[Next[i]]**，即 **W[t] = W[k]**；

所以：**W[0 : t] = W[i-t : i]**，所以，**Next[i + 1] = t +1**；



### 伪代码

#### 主程序

>* 输入：字符串**S**，字符串**W**（被查找）；
>* 输出：整数**P**（字符串**W**在**S**中的位置）
>* 令**j=1，k=1**；
>* 计算**T**数组
>* **while** j < len(S) **do**：
>  * **if** W[k] = S[j] **then**：
>    * j = j + 1；
>    * k = k + 1；
>    * **if** k = len(W) **then**：
>      * P = j - k；
>      * **return** P；
>  * **else**：
>    * k = T[k]；
>    * j = j + 1；

#### 计算T数组子程序

>* 输入：字符串**W**（被查找）；
>* 输出：数组**Next**；
>* 令：
>  * pos = 1：Next中当前计算的位置；
>  * cnd = 0;
>* Next[0] = 0；
>* **while** pos < len(W) **do**：
>  * **if** cnd > 1 **and** W[pos - 1] = W[cnd] **then**：
>    * Next[pos] = Next[cnd] + 1；
>    * pos = pos + 1；
>    * cnd = cnd +1；
>  * **else if** cnd = 0：
>    * Next[pos] = 0；
>    * cnd = cnd + 1；
>  * **else**：
>    * cnd = Next[cnd]；



## 代码

~~~c++
#include <stdio.h>
#include <string.h>
#define MAXN 10000

char W[MAXN];
char S[MAXN];
int Next[MAXN];

int KMP(char s[], char w[], int s_len, int w_len);
void get_next(char w[], int w_len, int next[]);

int main()
{
    printf("Input S:\n");
    scanf("%s", S);
    int s_len = strlen(S);
    printf("Input W:\n");
    scanf("%s", W);
    int w_len = strlen(W);
    printf("%d\n", KMP(S, W, s_len, w_len));
}

void get_next(char w[], int w_len, int next[])
{
    next[0] = 0;
    int i = 1, j = 0;
    while(i < w_len)
    {
        if(i > 1 && w[i - 1] == w[j])
            next[i++] = next[j++] + 1;
        else if(j == 0)
            next[i++] = 0;
        else
            j = next[j];
    }
}

int KMP(char s[], char w[], int s_len, int w_len)
{
    get_next(w, w_len, Next);
    for(int i = 0, j = 0; i < s_len;)
    {
        if(s[i] == w[j])
        {
            i++;
            j++;
        }
        else
        {
            j = Next[j];
            i++;
        } 
        if(j == w_len)
            return i - w_len + 1;
    }
    return -1;
}
~~~

[Code](https://github.com/baowj-678/Cpp/tree/master/Algorithm/KMP)

