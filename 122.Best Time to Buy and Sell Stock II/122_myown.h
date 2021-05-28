// DP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        //
        vector<vector<int>> dp(2,vector<int>(n,0));
        // dp[0][i] -- 第i天持股时的最大利润
        // dp[1][i] -- 第i天不持股时的最大利润
        dp[0][0] = -prices[0]; 
        dp[1][0] = 0;
        for(int i = 1; i < n; ++i)
        {
            dp[0][i] = max(dp[0][i-1], dp[1][i-1]-prices[i]);
            dp[1][i] = max(dp[1][i-1], dp[0][i-1]+prices[i]);
        }
        return dp[1][n-1];
    }
};

// DP(空间优化)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp0 = 0, dp1 = -prices[0];
        for (int i = 1; i < n; ++i) {
            int newDp0 = max(dp0, dp1 + prices[i]);
            int newDp1 = max(dp1, dp0 - prices[i]);
            dp0 = newDp0;
            dp1 = newDp1;
        }
        return dp0;
    }
};