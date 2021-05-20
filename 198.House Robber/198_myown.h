// 1. 递归回溯法 --- 时间超限
class Solution {
private:
    // 尝试从[index, nums.size()-1]中偷取，返回窃取到的最高金额
    int tryrob(vector<int>& nums, int index)
    {
        if (index >= nums.size())
            return 0;
        //
        int res = 0;
        for (int i = index; i < nums.size(); ++i)
            res = max(res, nums[i] + tryrob(nums, i + 2));
        return res;
    }
public:
    int rob(vector<int>& nums) {
        return tryrob(nums, 0);
    }
};

// 2. 递归回溯(空间优化)
class Solution {
private:
    vector<int> memo;
    // 尝试从[index, nums.size()-1]中偷取，返回窃取到的最高金额
    int tryrob(vector<int>& nums, int index)
    {
        if (index >= nums.size())
            return 0;
        //
        if (memo[index] != -1)
            return memo[index];
        //
        int res = 0;
        for (int i = index; i < nums.size(); ++i)
            res = max(res, nums[i] + tryrob(nums, i + 2));
        memo[index] = res;
        return res;
    }
public:
    int rob(vector<int>& nums) {
        memo = vector<int>(nums.size(), -1);
        return tryrob(nums, 0);
    }
};

// 3. DP
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 1)
            return 0;
        //
        // 状态 - 表示考虑窃取[i, n-1]房子的物品最大的价值
        vector<int> dp(n, -1);
        dp[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            for (int j = i; j < n; ++j)
                dp[i] = max(dp[i], nums[j] + ((j + 2) < n ? dp[j + 2] : 0));
        }
        //
        return dp[0];
    }
};

// 4. DP
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 1)
            return 0;
        //
        // 状态 - 表示考虑窃取[0, i]房子的物品最大的价值
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            for (int j = i; j >= 0; --j)
                dp[i] = max(dp[i], nums[j] + ((j - 2) >=0 ? dp[j - 2] : 0));
        }
        //
        return dp[n-1];
    }
};