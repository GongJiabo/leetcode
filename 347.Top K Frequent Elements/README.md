347. Top K Frequent Elements

给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

 

**示例 1:**

```
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
```

**示例 2:**

```
输入: nums = [1], k = 1
输出: [1]
```

**提示：**

- 1 <= nums.length <= 105

- k 的取值范围是 [1, 数组中不相同的元素的个数]
- 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的

**进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。**



### my_own:

使用哈希表（map）遍历数字，记录每个数出现的频率。

再用优先队列（priority_queue）—大根堆，遍历一遍map，保存topK频率的pair。

注意优先队列和哈希表中pair的键值对的顺序。



### solution：

快速排序

https://leetcode-cn.com/problems/top-k-frequent-elements/solution/qian-k-ge-gao-pin-yuan-su-by-leetcode-solution/

