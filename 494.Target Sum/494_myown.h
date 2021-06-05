// 1.递归迭代
class Solution {
public:
    int dfs(vector<int>& nums, int target, int index)
    {
        if(target == 0 && index == nums.size())
            return 1;
        if(index >= nums.size())
            return 0;
        //
        int ans = 0;
        ans += dfs(nums, target-nums[index], index+1);
        ans += dfs(nums, target+nums[index], index+1);
        return ans;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, target, 0);
    }
};

// 2. DP
// 注意状态转移数组的大小
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto a : nums)
            sum += a;
        //
        if(abs(target) > sum)
            return 0;
        //
        vector<vector<int>> dp(nums.size(), vector<int>(2*sum+1, 0));
        dp[0][sum + nums[0]] = 1;
        // 注意nums[0]=0的情况，因此为+=
        dp[0][sum - nums[0]] += 1;

        for(int i = 1;i<nums.size();++i)
        {
            for(int j=0; j<2*sum+1; ++j)
            {
                // dp[i][j] = dp[i-1][j+nums[i]] + dp[i-1][j-nums[i]];
                int r = j+nums[i] >= (2*sum+1) ? 0 : j+nums[i];
                int l = j-nums[i] < 0 ? 0 : j - nums[i];
                dp[i][j] = dp[i-1][l] + dp[i-1][r];
            }
        }

        return dp[nums.size()-1][target+sum];
    }
};

// 2.DP