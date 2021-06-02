//1. 贪心回溯法(时间超限)
// 1.1 想要总硬币数最少，肯定是优先用大面值硬币，所以对 coins 按从大到小排序
// 1.2 先丢大硬币，再丢会超过总额时，就可以递归下一层丢的是稍小面值的硬币
//2. 乘法对加法的加速
// 2.1 优先丢大硬币进去尝试，也没必要一个一个丢，可以用乘法算一下最多能丢几个
//      k = amount / coins[c_index] 计算最大能投几个
//      amount - k * coins[c_index] 减去扔了 k 个硬币
//      count + k 加 k 个硬币
// 2.2 如果因为丢多了导致最后无法凑出总额，再回溯减少大硬币数量
//3. 最先找到的并不是最优解
// 3.1 注意不是现实中发行的硬币，面值组合规划合理，会有奇葩情况
// 3.2 考虑到有 [1,7,10] 这种用例，按照贪心思路 10 + 1 + 1 + 1 + 1 会比 7 + 7 更早找到
// 3.3 所以还是需要把所有情况都递归完
//4. ans 疯狂剪枝
// 4.1 贪心虽然得不到最优解，但也不是没用的
// 4.2 我们快速算出一个贪心的 ans 之后，虽然还会有奇葩情况，但是绝大部分普通情况就可以疯狂剪枝了
class Solution {
public:
void coinChange(vector<int>& coins, int amount, int c_index, int count, int& ans) {
    if (amount == 0) {
        ans = min(ans, count);
        return;
    }
    if (c_index == coins.size()) return;

    for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--) {
        coinChange(coins, amount - k * coins[c_index], c_index + 1, count + k, ans);
    }
}

int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    sort(coins.rbegin(), coins.rend());
    int ans = INT_MAX;
    coinChange(coins, amount, 0, 0, ans);
    return ans == INT_MAX ? -1 : ans;
}

};

// 2. 动态规划
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < (int)coins.size(); ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
