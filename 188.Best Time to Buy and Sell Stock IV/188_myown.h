class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1 || k < 1)
            return 0;
        // dp[0][i] -- 第i天，完成了第一次买入操作的最大利润
        // dp[1][i] -- 第i天，完成了第一次卖出操作的最大利润
        // dp[2][i] -- 第i天，完成了第二次买入操作的最大利润
        // dp[3][i] -- 第i天，完成了第二次卖出操作的最大利润
        // ....
        // dp[2k-1][i] -- 第i天，完成了第k次卖出操作的最大利润
        vector<vector<int>> dp(2 * k, vector<int>(n, 0));
        //
        // 给边界条件，第0天完成第j次买入
        for (int j = 0; j < k; ++j)
            dp[2 * j][0] = -prices[0];
        // 第i天
        for (int i = 1; i < n; ++i)
        {
            // 第j/2 次操作： j-1 -- 买入   j+1 -- 卖出
            for (int j = 0; j < 2 * k; j += 2)
            {
                // 注意j-1的范围判断！！！
                // 第j次买入 = max(i-1天j次买入-不操作， i-1天j-1次卖出 - 今天买入)
                dp[j + 0][i] = max(dp[j + 0][i - 1], (j-1) < 0 ? -prices[i] : (dp[j - 1][i - 1] - prices[i]));
                // 第j次卖出 = max(i-1天j次卖出-不操作， i-1天j次买入 + 今天卖出)
                dp[j + 1][i] = max(dp[j + 1][i - 1], dp[j + 0][i - 1] + prices[i]);
            }
        }
        //
        return dp[2 * k - 1][n - 1];
    }
};