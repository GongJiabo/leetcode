// 递归回溯法
class Solution {
public:
    bool checkSub(const string& s, const string& t, int s1, int t1)
    {
        if(s1 == s.size())
            return true;
        if(t1 == t.size())
            return false;
        //
        bool res = false;
        if(s[s1] == t[t1])
            res = checkSub(s, t, s1 + 1, t1 + 1);
        else
            res = checkSub(s, t, s1, t1 + 1);
        return res;
    }

    bool isSubsequence(string s, string t) {
        return checkSub(s, t, 0, 0);
    }
};

// 双指针法
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ns = 0, nt = 0;
        while(ns < s.size() && nt < t.size())
        {
            if(s[ns] == t[nt])
            {
                ++ns;
                ++nt;
            }
            else
                ++nt;
        }
        if(ns == s.size())
            return true;
        return false;
    }
};