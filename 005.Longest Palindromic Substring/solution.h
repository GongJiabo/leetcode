#include <string>
using std::string;

class Solution {
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

public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len == 0) return s;
        int start = 0, last = 0;
        for (int i=0; i<len-1; ++i) {
            longestPalindrome(s, i, i, start, last);  //奇数情况
            longestPalindrome(s, i, i+1, start, last);//偶数情况 ？？同一个函数？
        }
        return s.substr(start, last-start+1);
    }
};

//时间复杂度应该在 O(n^2), 空间复杂度为 O(1). 属于常规解法。