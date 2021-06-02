// 贪心法(时间超限)
class Solution {
public:
    void dfs(vector<int>& coins, int amount, int index, int count, int& ans)
    {
        if(amount == 0)
        {
            ans = min(ans, count);
            return;
        }
        if(index >= coins.size() || amount < 0)
            return;
        //
        for(int i = amount/coins[index]; i>=0; --i)
            dfs(coins, amount - i*coins[index], index + 1, count + i, ans);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if( n < 1 || amount < 0)
            return -1;
        // 从大到小排列
        sort(coins.rbegin(), coins.rend());
        int ans = INT_MAX;
        dfs(coins, amount, 0, 0, ans);
        return ans==INT_MAX?-1:ans;
    }
};

// 2.DP
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if( n < 1 || amount < 0)
            return -1;
        //
        vector<int> dp(amount+1, amount+1);
        dp[0]=0;
        //
        for(int i=1; i<=amount; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(i-coins[j] < 0)
                    continue;
                dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
        //
        return dp[amount]>amount?-1:dp[amount];
    }
};