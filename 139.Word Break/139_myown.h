class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int n = s.size();
        if (n < 1 || wordDict.size() < 1)
            return false;
        //
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        //
        for (int i = 0; i <= n; ++i)
        {
            for (string& str : wordDict)
            {
                int len = str.size();
                if (i - len >= 0 && s.substr(i - len, len) == str)
                    dp[i] = dp[i] || dp[i - len];
            }
        }
        return dp[n];
    }
};