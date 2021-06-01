class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        // 状态矩阵
        // dp[0][i] -- 第i天交易完不持有股票的最大利润
        // dp[1][i] -- 第i天交易完持有股票的最大利润
        vector<vector<int>> dp(2, vector<int>(n, 0));
        dp[0][0] = 0;
        dp[1][0] = -prices[0];
        //
        for(int i = 1; i < n; ++i)
        {
            dp[0][i] = max(dp[0][i-1], dp[1][i-1] + prices[i] - fee);
            dp[1][i] = max(dp[1][i-1], dp[0][i-1] - prices[i]);
        }
        //
        return dp[0][n-1];
    }
};