class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return false;
        int sum = 0;
        for(auto x:nums)
            sum+=x;
        int maxNum = *max_element(nums.begin(), nums.end());
        // 如果和不是偶数，则不可分割
        if(sum % 2 != 0 || maxNum > sum/2)
            return false;
        int target = sum/2;

        // 设置状态变量
        // dp[i][j] 表示从数组的 [0,i] 下标范围内选取若干个正整数（可以是 0 个）
        // 是否存在一种选取方案使得被选取的正整数的和等于 j。
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        // 选择nums[0]的时候可以达到的容量
        dp[0][nums[0]] = true;
        // 达到0容量，[0,n-1]中所有的组合都不选
        for(int i=0;i<n;++i)
            dp[i][0] = true;
        //
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < target + 1; ++j)
            {
                if(j-nums[i]>=0)
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n-1][target];
    }
};

// 2.DP(空间优化)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }
        if ((sum & 1) == 1) {
            return false;
        }

        int target = sum / 2;
        vector<bool> dp(target + 1);
        dp[0] = true;

        for(int num: nums){
            for(int i = target; i >= num; i--){
               
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[target];
        
    }
};

// 3. 递归
class Solution {
public:

    // 使用nums[0....index], 是否可以完全填充一个容量为sum的背包
    bool tryPartition(vector<int>& nums, int index, int sum)
    {
        if(sum == 0)
            return true;
        //
        if(sum<0 || index<0)
            return false;
        //
        return tryPartition(nums, index-1, sum) || 
                tryPartition(nums, index-1, sum - nums[index]);
    }

    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        if(n<=1)
            return false;
        //
        int sum = 0;
        for(int i = 0; i<nums.size(); ++i)
        {
            assert(nums[i] > 0);
            sum += nums[i];
        }
        if(sum%2 != 0)
            return false;
        //
        return tryPartition(nums, n-1, sum/2);
    }
};

// 递归(空间优化)
 class Solution {
private:
    // memo[i][c]表示索引为[0...i]的这些元素，是否可以完全填充一个容量为c的背包
    // -1表示未计算; 0表示不可以填充; 1表示可以填充
    vector<vector<int>> memo;
public:
    // 使用nums[0....index], 是否可以完全填充一个容量为sum的背包
    bool tryPartition(vector<int>& nums, int index, int sum)
    {
        if(sum == 0)
            return true;
        //
        if(sum<0 || index<0)
            return false;
        //
        if(memo[index][sum] != -1)
            return memo[index][sum] == 1;
        //
        memo[index][sum] = (tryPartition(nums, index-1, sum) || tryPartition(nums, index-1, sum - nums[index])) ? 1 : 0;
        return memo[index][sum] == 1;
    }

    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        if(n<=1)
            return false;
        //
        int sum = 0;
        for(int i = 0; i<nums.size(); ++i)
        {
            assert(nums[i] > 0);
            sum += nums[i];
        }
        if(sum%2 != 0)
            return false;
        //
        memo = vector<vector<int>> (n, vector<int>(sum/2+1, -1));
        return tryPartition(nums, n-1, sum/2);
    }
};