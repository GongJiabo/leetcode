040.Combination Sum II

给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]

solution:
要额外注意的有两点：

Each number in C may only be used once in the combination.
The solution set must not contain duplicate combinations.
对于第一点，我们可以在递归中，给下一个 start 传参为 i+1 来解决。

对于第二点，有两种思路：

使用 std::set<vector<int>> 来存储返回值，缺点是效率较低。
在递归函数中增加条件：if (i > start && num[i] == num[i-1]) continue; 无比轻巧的避过了重复项。
我当然选择了第二种，效率遥遥领先呢。