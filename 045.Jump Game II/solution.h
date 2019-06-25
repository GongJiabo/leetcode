// ver 1

#include <algorithm>

class Solution {
public:
    int jump(int A[], int n) {
        int step = 0, max = 0;
        for (int i=0, tmpMax=0; i<=max && i<n-1; ++i) {
            tmpMax = std::max(tmpMax, A[i]+i);
            if (i == max) { max = tmpMax; ++step; }
        }
        return max >= (n-1) ? step : -1;
    }
};

// ver 2

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        for(int i = nums.size()-2;i>=0;--i){
            if(nums[i]==0) continue;
            if(nums[i] + i>=nums.size()-1){
                dp[i] = 1;
            }
            else if(nums[i+1] == nums[i] - 1){
                    dp[i] = dp[i+1];
                }
            else{
                int min_val = INT_MAX;
                for(int j = i+nums[i]; j>i;--j){
                    if(dp[j]<min_val&&dp[j]) min_val = dp[j];
                }
                dp[i] =( min_val == INT_MAX )? 0 :min_val + 1;
            }
        }
       return dp[0];
    }
};
