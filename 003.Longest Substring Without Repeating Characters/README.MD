003.Longest Substring Without Repeating Characters

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
	 
	
	
003_myown:
算法提交执行时间超出限制，时间复杂度在O（n三次方），算法需要优化！！
1. 滑动窗口从n开始缩小
2. 从后往前插入并查找是否重复，记录各不重复的子字符串长度进行比较
优化算法：
如果给一个例子"abcabcbb"，让你手动找无重复字符的子串，该怎么找？一个字符一个字符的遍历，比如a，b，c，然后又出现了一个a，那么此时就应该去掉第一次出现的a，然后继续往后，又出现了一个b，则应该去掉一次出现的b，以此类推，最终发现最长的长度为3。所以说，我们需要记录之前出现过的字符，记录的方式有很多，最常见的是统计字符出现的个数，但是这道题字符出现的位置很重要，所以我们可以使用HashMap来建立字符和其出现位置之间的映射。进一步考虑，由于字符会重复出现，到底是保存所有出现的位置呢，还是只记录一个位置？我们之前手动推导的方法实际上是维护了一个滑动窗口，窗口内的都是没有重复的字符，我们需要尽可能的扩大窗口的大小。由于窗口在不停向右滑动，所以我们只关心每个字符最后出现的位置，并建立映射。窗口的右边界就是当前遍历到的字符的位置，为了求出窗口的大小，我们需要一个变量left来指向滑动窗口的左边界，这样，如果当前遍历到的字符从未出现过，那么直接扩大右边界，如果之前出现过，那么就分两种情况，在或不在滑动窗口内，如果不在滑动窗口内，那么就没事，当前字符可以加进来，如果在的话，就需要先在滑动窗口内去掉这个已经出现过的字符了，去掉的方法并不需要将左边界left一位一位向右遍历查找，由于我们的HashMap已经保存了该重复字符最后出现的位置，所以直接移动left指针就可以了。我们维护一个结果res，每次用出现过的窗口大小来更新结果res，就可以得到最终结果了。
相应代码见003_myown_improve.h
参考blog：
https://www.cnblogs.com/ariel-dreamland/p/8668286.html


solution:
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;
#include <algorithm>
using std::max;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t ret = 0, start = 0;
        unordered_map<char, size_t> trace;       //键值对
        for (size_t i = 0; i < s.size(); ++i) {
            auto found = trace.find(s[i]);
            if (found != trace.end() && found->second >= start) {
                ret = max(ret, i - start);     //计算子字符串长度取最大
                start = found->second + 1;
            }
            trace[s[i]] = i;   //trace—>first只有a/b/c三种值，不停修改其对应的i（second不停覆盖），即保存从左向右遍历的最近出现的abc的位置
        }
        return max(ret, s.size() - start);
    }
};

设 substr 的起点为 start(s), 终点为 last(l). 每一次迭代，记录一张索引表。

abcabcbb
^  ^
s  l
char	pos
a	0
b	1
c	2
上图所示，last 指向 a, 查询当前表可知，a 的位置记录在案，且 pos >= start. 故此刻诞生一个 substr. 长度为 last - start. s 更新位置为 pos + 1.
思想同优化算法