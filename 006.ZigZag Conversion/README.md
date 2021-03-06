006.ZigZag Conversion

将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G

my_own:
根据输入的行数，Z形规律重新排列字符串，没有特殊算法。

solution：
这道题为了效率，肯定希望在一次迭代中完成对字符串的分组。而经过简单的分析，可以发现迭代的索引与分组的索引有非常规律的对应关系。

对(nRows-1)取余，可以区分行数。
对(nRows-1)做除，可以区分当前是上升还是下降（偶数上升，奇数下降）