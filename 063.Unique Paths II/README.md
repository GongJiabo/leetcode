63. Unique Paths II

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

![jpg](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/robot_maze.png)

网格中的障碍物和空位置分别用 1 和 0 来表示。

说明：m 和 n 的值均不超过 100。

示例 1:

输入:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

输出: 2

解释:

3x3 网格的正中间有一个障碍物。

从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右


solution(from pezy):

道题增加了一个限制条件，路径上出现两种状态：此路可通（0），此路不通（1）。且参数也变成了一个二维的 vector.

但这并不妨碍我们继续使用动态规划算法，依旧是弄一个数组（记录到某个位置所有可能的路径数），先读取二维矩阵的第一行（如果有的话）。假设第一行如下：

```cpp
 0 0 0 1 0 1 0 0
       ^
//   出现1，表示横着的这条路不通，那么其后续的全部位置（包括自身），都应该是0。变成下面这个样子：

 1 1 1 0 0 0 0 0

// 如何实现上述的转变？
vector<int> vec(obstacleGrid.front().cbegin(), obstacleGrid.front().cend()); // 读取第一行
auto flag = std::find(vec.begin(), vec.end(), 1); // 找到第一个出现的1所在位置，若没有 flag == vec.end();
std::fill(vec.begin(), flag, 1); // 将前面的节点置为1
std::fill(flag, vec.end(), 0); // 将后面的节点置为0
```

后面的过程与 29 题几乎一致了。除了第一列外，基本遵循以下逻辑：

- 如果 obstacleGrid[i][j] 为 1， 表示此路不同， vec[j] = 0; 一条路径都无。
- 如果 obstacleGrid[i][j] 为 0， 和之前一样, vec[j] += vec[j-1];
- 对于第一列来说，obstacleGrid[i][0] 为 1，应将 vec[0] = 0; 但如果为 0，则应该进入下一次迭代。

很巧妙!!!使用一维的数组就可以完成计算!!正确初始化很重要