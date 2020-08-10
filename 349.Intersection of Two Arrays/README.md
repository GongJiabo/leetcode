349. Intersection of Two Arrays

示例 1：
```
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
```
示例 2：

```
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
```

说明：

- 输出结果中的每个元素一定是唯一的。
- 我们可以不考虑输出结果的顺序。
 
 
 ---------
 
 ### my_own:
 
利用C++的STL库—set，set不予许元素重复。

tips:
std::set和std::multiset底层实现都是红黑树，std::unordered_set的底层实现是哈希表。

使用unordered_set 读写效率是最高的，我们并不需要对数据进行排序，而且还不要让数据重复，所以选择unordered_set。
