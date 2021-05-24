class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 1)
            return 0;
        // 建立DP数组
        vector<vector<int>> dp(3,vector<int>(n));
        // dp[0][i] - 在第i天持有股票的最大收益
        dp[0][0] = - prices[0];
        // dp[1][i] - 在第i天不持有股有票，且在冷却期（i天卖出，i+1天冷却）的最大收益
        dp[1][0] = 0;
        // dp[2][i] - 在第i天不持有股票，且不在冷却期的最大收益
        dp[2][0] = 0;
        //
        for(int i = 1; i < n; ++i)
        {
            // 第i天持有股票的最大收益：1、不操作，i-1天的收益；2、买入股票
            dp[0][i] = max(dp[0][i-1], dp[2][i-1]-prices[i]);
            // 第i天不持有股票，且在冷却期的最大收益：当天卖出
            dp[1][i] = dp[0][i-1] + prices[i];
            // 第i天不持有股票，且不在冷却期的最大收益：1、不操作；2、当天卖出
            dp[2][i] = max(dp[2][i-1], dp[1][i-1]);
        } 
        //
        int res = max(dp[1][n-1], dp[2][n-1]);
        return res;
    }
};