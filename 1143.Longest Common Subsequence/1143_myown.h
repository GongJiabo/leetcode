// 动态规划
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        //
        if(n1 < 1 || n2 < 1)
            return 0;
        //
        // 设置状态矩阵
        // dp[i][j]表示text1[0...i)与text2[0...j)中最长公共子序列的长度
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        dp[1][1] = text1[0] == text2[0] ? 1 : 0;
        for(int i = 1; i <= n1; ++i)
        {
            // text1[0...i)
            for(int j = 1; j <= n2; ++j)
            {
                // text2[0...j)
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        //
        return dp[n1][n2];
    }
};