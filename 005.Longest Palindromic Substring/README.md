005.Longest Palindromic Substring
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

my_own：
中心对称思想，由于回文子串奇数与偶数长中心点不同，需要分情况讨论
循环遍历，以每个点位中心点寻找对称的字符串长度，取最大的。
不要忘记处理空字符串与单个字符的情况！！！
solution：
思想相同，用同一个函数处理奇数与偶数的情况
内部比较新计算出的b,e与start,last大小，简洁！！！
void longestPalindrome(const string& s, int b, int e, int &start, int &last) {
		 // 这个函数尝试对现有子串首尾扩张，若出现更大的长度，则记录之。
        int len = s.size();
        while (b >= 0 && e < len && s[b] == s[e])
            --b, ++e;
        ++b, --e;
        if (e - b > last - start) {
            start = b;
            last = e;
        }
    }
	
	