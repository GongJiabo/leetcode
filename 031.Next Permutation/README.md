031.Next Permutation

实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

my_own:
从后往前遍历容器，观察是否为按顺序排列, 如果出现nums[i+1]<nums[i]的情况，说明当前构成的数值不是最大。
寻找i到末尾的数值最小的比nums[i+1]大的数与其交换位置，对后面的数字排序成最小即可。

solution(Quote):
此题也存在逗逼的写法：

    std::next_permutation(num.begin(), num.end());

仅此一句话，保证以最高效的姿势 AC。

-----

所以显然，这道题就是让我们实现该函数的功能了。我们先用这个 STL 的函数写一段测试代码，来探索其排列组合的规律性。

```cpp
#include <iostream>
#include <array>
#include <algorithm>

int main()
{
std::array<int, 4> A = {1,2,3,4};
do {
    for (auto i : A)
        std::cout << i << " ";
        std::cout << std::endl;
    } while (std::next_permutation(A.begin(), A.end()));
}
```

输出（截取部分）：

    1 2 3 4 // 2->3->4 : ascending
    1 2 4 3
    1 3 2 4
    1 3 4 2
    1 4 2 3
    1 4 3 2 // 4->3->2 : descending
    2 1 3 4
    2 1 4 3
    2 3 1 4

大体上我们可以看出一点端倪：

1. 总体上是从小到大。如从 1 开头，到 2 开头。
2. 当 1 开头时，将全部 1 开头的组合列完。
3. 如何保证第 2 条？发现规律是，除去开头的 1 ，剩下三个数，呈这样的规律：从**递增**排列到**递减**。
4. 第 3 条是大方向，我们再细究每一步。发现局部范围内，也是将**递增**变为**递减**，如 3,4 -> 4,3

综上，我们若要得到下一步的组合，应该将注意力集中在**递增**的子序列上，设置两个指针，start 与 last，分别指向**递增子序列**的手尾，用此来重点分析一下从第二行到第三行的转变。

    1 2 4 3
    ^ ^
    s l

这种情况下， s 指向了 2，意味着 1,2 开头的组合已经排列完毕，根据第 1 条，我们希望去排列 1,3 开头的组合了。而此刻 3 在行尾，我们就希望**将其提取到 2 的前头去**。即变成：

    1 3 2 4

果然就是咱们想要的了。可是这个插入过程实际上应分为两步：

1. swap(2, 3);
2. 4 以后的元素全部逆序

解释一下第二步，当 last 指向 4，这已经意味着 4 以后一定是降序的，即使交换了 2,3 也无法改变这个顺序。而我们所希望的，显然是保持 2,4 这样的升序，作为 1,3 开头排列的起始。所以才有了第二步的逆序。

----

讲明算法，再来理一理实现思路。

首先，如果 num 为空，或者就只有一个元素，显然是不存在什么排列的，直接返回。
然后，需要初始化 start 的位置，我们希望从后往前找，故初始状态下，`auto start = prev(num.end());`，指向最后一个元素。
最后，开始迭代过程，定位 start 与 last 的位置，直接见代码：

```cpp
for (;;) {
    auto last = start--; // 让 last 指向最后一个元素，并将 start 前移。
    if (*start < *last) { // 定位升序子序列
        auto riter = num.end(); // 从尾部开始寻找下一次组合的开头元素
        while (!(*start < *--riter)) ; // 寻找过程，一旦大于 start 所指，即为所要。
        std::iter_swap(start, riter); // 交换过程
        std::reserve(last, num.end()); // 逆序过程
        return;
    }
    if (start == num.begin()) { // 特殊情况：若全部元素都已经排列完毕(整体降序)，回到初始(整体升序)
        std::reverse(num.begin(), num.end());
        return;
    }
}
```