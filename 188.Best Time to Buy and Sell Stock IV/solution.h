// 1. 动态规划(二维数组)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
        for (int j = 1; j < 2 * k; j += 2) {
            dp[0][j] = -prices[0];
        }
        for (int i = 1;i < prices.size(); i++) {
            for (int j = 0; j < 2 * k - 1; j += 2) { 
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
                dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
            }
        }
        return dp[prices.size() - 1][2 * k];
    }
};

// 2. 动态规划
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        k = min(k, n / 2);
        vector<vector<int>> buy(n, vector<int>(k + 1));
        vector<vector<int>> sell(n, vector<int>(k + 1));

        buy[0][0] = -prices[0];
        sell[0][0] = 0;
        for (int i = 1; i <= k; ++i) {
            buy[0][i] = sell[0][i] = INT_MIN / 2;
        }

        for (int i = 1; i < n; ++i) {
            buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
            for (int j = 1; j <= k; ++j) {
                buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
                sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);   
            }
        }

        return *max_element(sell[n - 1].begin(), sell[n - 1].end());
    }
};


