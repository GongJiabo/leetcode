class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(int num : nums) sum += num;
        if(S > sum || (S + sum) % 2 == 1) return 0;
        int target = (S + sum) / 2;
        vector<int> dp(target + 1);
        dp[0] = 1;
        for(int num : nums){
            for(int i = target; i >= num; i--){               
                dp[i] = dp[i] + dp[i - num];
            }
        }
        return dp[target];
    }
};