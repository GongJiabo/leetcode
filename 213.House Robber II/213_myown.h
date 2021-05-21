class Solution {
private:
    vector<int> memo;
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        //
        memo = vector<int>(n, -1);
        int res1 = my_rob(nums, 1, n);
         memo = vector<int>(n, -1);
        int res2 = my_rob(nums, 0, n - 1);
        return max(res1, res2);
    }

    int my_rob(vector<int>& nums, int begin, int end) {
        if(begin >= end)
            return 0;
        //
        if(memo[begin] != -1)
            return memo[begin];
        int res = 0;
        for(int i = begin; i < end; ++i)
            res = max(res, nums[i]+my_rob(nums,i+2,end));
        //
        memo[begin] = res;
        return res;
    }
};
