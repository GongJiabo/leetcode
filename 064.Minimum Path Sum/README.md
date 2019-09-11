64. Minimum Path Sum

给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。

my_own:

动态规划，在原数组上操作

对每个位置上左边left和上边up的值进行比较，选择小的值加上当前值

注意边界位置的计算

solution：

可以看到，在最后一步的选择中，要么选择从上面下来，要么选择从左边过来，很显然，选择小的那个。那么 DP 公式呼之欲出：

    f[i][j] = min(f[i-1][j], [i][j-1]) + grid[i][j];

于是咱们就可以采取和上一道题同样的方式，用DP的思路来进行迭代了。（迭代过程中记录每一步的解）

比那道题要好的一点在于，这次给的是一个 vector，而且采用的是 reference 的方式，很显然，我们根本不需要额外使用空间，只需要将时间复杂度尽量降低即可。

我绘制了一幅图，可以理顺整个流程：

![qq 2014112109024](https://cloud.githubusercontent.com/assets/1147451/5136536/a308d496-7164-11e4-8bef-82a634b85489.png)

有几个特殊情况要考虑：

1. 对于第一格，跳过，因为必选。
2. 对于第一行，f[i][j] = grid[i][j] + grid[i][j-1]
3. 对于第一列，f[i][j] = grid[i][j] + grid[i-1][j]
4. 其余情况下，f[i][j] = min(grid[i][j-1], grid[i-1][j]) + grid[i][j]

然后，几乎代码呼之欲出了。。。