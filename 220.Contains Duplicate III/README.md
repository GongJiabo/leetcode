220. Contains Duplicate III

在整数数组 `nums` 中，是否存在两个下标 `i` 和 `j`，使得 `nums [i]` 和 `nums [j]` 的差的绝对值小于等于 `t` ，且满足 `i` 和 `j` 的差的绝对值也小于等于 `ķ` 。

如果存在则返回 `true`，不存在返回 `false`。

 

__示例 1__:
```
输入: nums = [1,2,3,1], k = 3, t = 0
输出: true
```
__示例 2__:
```
输入: nums = [1,0,1,1], k = 1, t = 2
输出: true
```
__示例 3__:
```
输入: nums = [1,5,9,1,5,9], k = 2, t = 3
输出: false
```

------------------
### solution:
```
1.用set，自动排序，为下文使用lower_bound()函数做铺垫   
2.|nums[i] - nums[j]| <= t 等效于：  
1.当nums[i] > nums[j]时，nums[i] - nums[j] <= t ——> nums[j] = nums[i] - t  
2.当nums[i]<nums[j]时，nums[j] - nums[i] <= t ——> nums[j] = nums[i] + t 3.所以nums[i] - t <= nums[j] <= nums[i] + t
3.lower_bound(x)函数返回set当中，第一个大于等于x的指针，相当于nums[i] - t <= nums[j]，找到nums[j]
4.long防止溢出
5.插入一个，删除一个，保证滑动窗口大小不变
```
 