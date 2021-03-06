class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 1 || target < 1)
            return 0;
        //
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int i=1; i<=target; ++i)
        {
            for(int j=0; j<nums.size();++j)
            {
                if(i>=nums[j] && dp[i - nums[j]] < INT_MAX - dp[i])
                    dp[i]+=dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};