//对比两个字符串对应位置的字符在字符串内第一次出现的位置。
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (0 == s.size() && 0 == t.size())
        {
            return true;
        }

        for (int index = 0; index <= s.size() - 1; index++)
        {
            if (s.find(s[index]) != t.find(t[index]))
            {
                return false;
            }
        }

        return true;
    }
};
