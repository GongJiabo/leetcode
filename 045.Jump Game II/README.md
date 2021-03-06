045. Jump Game II

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明:

假设你总是可以到达数组的最后一个位置。


### 1.Quote:https://www.cnblogs.com/grandyang/p/4373533.html

我们需要两个变量cur和pre分别来保存当前的能到达的最远位置和之前能到达的最远位置，只要cur未达到最后一个位置则循环继续，pre先赋值为cur的值，表示上一次循环后能到达的最远位置，如果当前位置i小于等于pre，说明还是在上一跳能到达的范围内，我们根据当前位置加跳力来更新cur，更新cur的方法是比较当前的cur和i + A[i]之中的较大值，如果题目中未说明是否能到达末尾，我们还可以判断此时pre和cur是否相等，如果相等说明cur没有更新，即无法到达末尾位置，返回-1

### 2.动态规划 + 贪心来做。

这道题可以很简单的想到 用搜索去做，但是如果从起点到终点 直接搜索的话会超时，

我们倒着从终点搜索回来，dp[i] 表示 从 i 到终点的最近的 步数。

dp[i] = 1 + min{ dp[i+1] , dp[i+2] , dp[i+3] ....... dp[nums.size()-1]}

也就是当前i 位置可以去的最短的一个路径。

这里可以进行一些简单的剪纸

如果这个num[i] == 0 可以直接宣判这个 dp[i] = INT_MAX 是不能到达终点的。

如果 i + nums[i] >= nums.size()-1 则说明这个 i 可以一步到位 直接赋值为 1

如果 nums[i+1] == nums[i] - 1 的时候 ，例如 3 ,2 ,1 ，1 ，1 可以说我们

dp[i] = dp[i+1]

否则采取贪心的做法去找寻 最小的一个.