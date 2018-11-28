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
	
ps：
1）动态规划求解：
https://www.cnblogs.com/coderJiebao/p/Algorithmofnotes30.html
下面介绍动态规划的方法，使用动态规划可以达到最优的 O(n2) 复杂度。

　　令 dp[i][j] 表示 S[i] 至 S[j] 所表示的子串是否是回文子串，是则为 1，不是则为 0。这样根据 S[i] 是否等于 S[j] ，可以把转移情况分为两类：

 若 S[i] == S[j]，那么只要 S[i+1] 至 S[j-1] 是回文子串，S[i] 至 S[j] 就是回文子串；如果S[i+1] 至 S[j-1] 不是回文子串，则 S[i] 至 S[j] 也不是回文子串。
 若 S[i] != S[j]，那么 S[i] 至 S[j] 一定不是回文子串。　　　　
　　由此可以写出状态转移方程：

　　　　　　　　　　dp[i][j]={dp[i+1][j−1],S[i]==S[j]0,S[i]!=S[j]

　　边界：dp[i][i]=1，dp[i][i+1] = (S[i] == S[i+1]) ? 1 : 0。

　　根据递推写法从边界出发的原理，注意到边界表示的是长度为 1 和 2 的子串，且每次转移时都对子串的长度减了 1，因此不妨考虑按子串的长度和子串的初始位置进行枚举，即第一遍将长度为 3 的子串的 dp 值全部求出，第二遍通过第一遍结果计算出长度为 4 的子串的 dp 值 ……

2）Manacher法
https://www.cnblogs.com/mini-coconut/p/9074315.html
can't understand...如何得到转换后的Len数组？？
	
	