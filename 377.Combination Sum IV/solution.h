// 1.DP
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int& num : nums) {
                if (num <= i && dp[i - num] < INT_MAX - dp[i]) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};

// 2.记忆化递归
class Solution {
public:
    unordered_map<int,int> m;
    int combinationSum4(vector<int>& nums, int target) {
        int res=0;
        res=dfs(target,nums);
        return res;
    }
    int dfs(int& target,vector<int>& nums){
        if(target==0){
            return 1;
        }
        if(target<0){
            return 0;
        }
        if(m.count(target)){
            return m[target];
        }
        int counting=0;
        for(int i=0;i<nums.size();i++){
            target-=nums[i];
            counting+=dfs(target,nums);
            target+=nums[i];
        }
        m[target]=counting;
        return counting;
    }
};