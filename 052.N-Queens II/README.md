052. N-Queens II

n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

![alt 属性文本](./8-queens.png)

上图为 8 皇后问题的一种解法。

给定一个整数 n，返回 n 皇后不同的解决方案的数量。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例:

输入: 4  
// 解法 1   
输出: [  
 [".Q..",  
  "...Q",  
  "Q...",  
  "..Q."],  
  // 解法 2  
 ["..Q.",  
  "Q...",  
  "...Q",  
  ".Q.."]  
]  
解释: 4 皇后问题存在两个不同的解法。


同051题