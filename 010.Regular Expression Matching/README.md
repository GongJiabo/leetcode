# 010.Regular Expression Matching

给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符。
'*' 匹配零个或多个前面的元素。
匹配应该覆盖整个字符串 (s) ，而不是部分字符串。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "a*"
输出: true
解释: '*' 代表可匹配零个或多个前面的元素, 即可以匹配 'a' 。因此, 重复 'a' 一次, 字符串可变为 "aa"。
示例 3:

输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个('*')任意字符('.')。
示例 4:

输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 'c' 可以不被重复, 'a' 可以被重复一次。因此可以匹配字符串 "aab"。


my_own:
这道求正则表达式匹配的题和那道 Wildcard Matching 通配符匹配的题很类似，不同点在于*的意义不同，在之前那道题中，*表示可以代替任意个数的字符，而这道题中的*表示之前那个字符可以有0个，1个或是多个，就是说，字符串a*b，可以表示b或是aaab，即a的个数任意，这道题的难度要相对之前那一道大一些，分的情况的要复杂一些，需要用递归Recursion来解，大概思路如下：

- 若p为空，若s也为空，返回true，反之返回false

- 若p的长度为1，若s长度也为1，且相同或是p为'.'则返回true，反之返回false

- 若p的第二个字符不为*，若此时s为空返回false，否则判断首字符是否匹配，且从各自的第二个字符开始调用递归函数匹配

- 若p的第二个字符为*，若s不为空且字符匹配，调用递归函数匹配s和去掉前两个字符的p，若匹配返回true，否则s去掉首字母

- 返回调用递归函数匹配s和去掉前两个字符的p的结果

ps:
https://www.cnblogs.com/grandyang/p/4461713.html

solution（思路相同）:
思路是，要判断字符串，肯定要从字符开始。这就简化了问题，比较两个字符是否匹配很容易。

// char s,p;
if (s == p || (p == '.' && s != '\0')) // same character.
首先，迭代 p，如果 *p == '\0'，那么可以直接返回 return *s == '\0';

其次，判断后面有没有跟*，即 if (p[1] != '*') 那么就正常比较当前字符。若跟了 *， 则与判断 isMatch(s, p+2) 无异。（因为 * 可以代表0）

最后，一旦出现不同字符，直接返回 false。

代码很简单，5行搞定。
