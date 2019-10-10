76. Minimum Window Substring

给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"  
输出: "BANC"  

说明：  

- 如果 S 中不存这样的子串，则返回空字符串 ""。  
- 如果 S 中存在这样的子串，我们保证它是唯一的答案。


-------

### my_own:

1. 暴力解法，遍历所有子字符串，寻找最短的包含所需字符串的子串。  
第一次解时，使用find匹配T字符串中的字符，但是发现重复的时候，如S=“A”，T=“AA”时会出现bug。  
需要将匹配后的字符去除掉，或者同级字符出现的个数。暴力算法超出时间限制。

2. 滑动窗口，见leetcode题解，十分精妙！  
- https://leetcode-cn.com/problems/minimum-window-substring/solution/hua-dong-chuang-kou-suan-fa-tong-yong-si-xiang-by-/

-------

### solution(from leetcode):  
作者：ivan_allen  
链接：https://leetcode-cn.com/problems/minimum-window-substring/solution/76-zui-xiao-fu-gai-zi-chuan-cshuang-zhi-zhen-mo-ba/  

