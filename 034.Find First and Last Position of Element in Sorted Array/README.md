034. Find First and Last Position of Element in Sorted Array

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

My_own:
二分查找出target所在的位置，在从该位置左右遍历出起始与结束位置。

Solution：
思路一样，但是算法内存消耗和执行时间不算好，寻求更好的解法。
