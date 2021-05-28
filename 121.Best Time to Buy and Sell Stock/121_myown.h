// 1. 双重循环(时间超限)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        //
        int profit = 0;
        for(int i=0; i<n; ++i)
        {
            for(int j=i+1; j<n; ++j)
            {
                profit = max(profit, prices[j]-prices[i]);
            }
        }
        //
        return profit;
    }
};

// 2. DP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        //
        vector<vector<int>> dp(2,vector<int>(n,0));
        // dp[0][i], 第i天持股：1、i-1天持股，今天不操作；2、i-1天不持股，今天买入
        dp[0][0] = -prices[0];
        // dp[1][i], 第i天不持股：1、i-1天持股，今天卖出；2、i-1天不持股，今天不操作
        dp[1][0] = 0;
        for(int i=1; i<n; ++i)
        {
            dp[0][i] = max(dp[0][i-1], -prices[i]);
            dp[1][i] = max(dp[0][i-1]+prices[i], dp[1][i-1]);
        }
        //
        return dp[1][n-1];

    }
};

// 3.一次遍历
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minprice = INT_MAX;
        for(int i=0; i<prices.size();++i)
        {
            profit = max(profit, prices[i] - minprice);
            minprice = min(minprice, prices[i]);
        }
        return profit;
    }
};