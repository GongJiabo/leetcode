69. Sqrt(x)

实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。


solution(from pezy):

-----

抛开上述轶事不谈，平心而论此题如果只是一道寻常数学题，用程序应该如何解之。

首先最自然的方案，当然是对对碰。如求 10 的平方根，我可以从 1 开始碰，`1*1==1` 显然不对，一直到 `4*4==16` 才发现超出了。于是答案显然是 3.

但这种类似穷举的方式显然很不智，既然是查找能碰对的数，肯定二分搜索要快一些。 如先看 `5*5==25`, 25 > 10, 范围向左缩小，并继续中分，有 `3*3==9`，9 < 10，范围向右缩小，并继续中分，有 `4*4==16`, 16 > 10, right == 3, left == 4. 结束。

那结果应该取哪一次的 middle 呢？显然因为咱们是 integer 的运算，取小不取大，3 可以是结果，4 决计不是。故有：

     if (mid <= x / mid) ret = mid;

整个程序非常简单，而且高效 AC:

```cpp
int l = 1, r = x, ret = 0;
while (l <= r) {
     int m = (l + r) >> 1;
     if (m <= x / m) { l = m+1; ret = m; }
     else r = m-1;
}
return ret;
```

-----

这道题算是告一段落，但我们其实占了 integer 的便宜，假使要实现的是 `float sqrtf(float x)`, 我们可能需要考虑一下使用著名的[牛顿迭代](http://www.matrix67.com/blog/archives/361)了。这就基本演变为一道数学题了。具体可见 Matrix67 这篇博文中的解释。

```cpp
#include <cfloat>
#include <cmath>

float sqrtf(float x) {
    float ret;
    for (float f = 1.f; true; f = ret) {
        ret = (f + x / f) / 2;
        if (std::abs(f - ret) < FLT_MIN) break;
    }
    return ret;
}

```
