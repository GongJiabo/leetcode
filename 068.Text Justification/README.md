68. Text Justification

给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入额外的空格。

说明:

单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。
示例:

输入:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
输出:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
示例 2:

输入:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
输出:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
     因为最后一行应为左对齐，而不是左右两端对齐。       
     第二行同样为左对齐，这是因为这行只包含一个单词。
示例 3:

输入:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
输出:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]

***

### my_own:

先统计每行单词的个数，再分别处理每行。

难点在于每行空格的分配，因为要求每个单词之前的空格一致，因此采用循环逐个加入单词之间的空格。

对只有一个单词的情况以及最后一行做特殊处理。

算法需要遍历容器多遍，还需要保存每行的单词，时间与空间复杂度较高。

***

### solution:

没想到什么巧妙的解法，按照题目给出的几种情况分类写出每行的处理方法即可。
ans保存结果，begin保存当前行首个单词在words中的位置，width保存当前行所有单次的总宽度。

需要处理的行分为3种：

1. 非末尾行，有一个以上单词。通过单词总数和剩余空格数分配每两个单词间的空格数。

2. 非末尾行，仅有一个单词。该单词靠左填入行中，右侧由空格补齐。

3. 末尾行。每个单词间有一个空格，空出的右侧由空格补齐。

作者：gremist
链接：https://leetcode-cn.com/problems/text-justification/solution/c-fen-lei-tao-lun-ti-jie-by-gremist/

