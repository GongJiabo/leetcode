// 1. 递归回溯
class Solution {
public:
    /* 两次动态规划 */
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(my_rob(nums, 1, n), my_rob(nums, 0, n - 1));
    }

    /* 动态规划 + 滚动数组 */
    /* x, y, z 分别表示前i - 2， i - 1, i个房屋所能偷到的最大值 */
    int my_rob(vector<int>& nums, int begin, int end) {
        int n = end - begin;
        int x = nums[begin], y = max(nums[begin], n > 1 ? nums[begin + 1] : 0), z;
        for (int i = begin + 2; i < end; ++i) {
            z = max(x + nums[i], y);
            x = y;
            y = z;
        }
        return y;
    }
};

// 2. DP
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int result1 = robRange(nums, 0, nums.size() - 2); // [0, nums.size()-2]中窃取
        int result2 = robRange(nums, 1, nums.size() - 1); // [1, nums.size()-1]中窃取
        return max(result1, result2);
    }
    // 198.打家劫舍的逻辑
    int robRange(vector<int>& nums, int start, int end) {
        if (end == start) return nums[start];
        vector<int> dp(nums.size());
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }
};

// 3. DP(空间优化)
class Solution {
public:
    int robRange(vector<int>& nums, int start, int end) {
        int first = nums[start], second = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }

    int rob(vector<int>& nums) {
        int length = nums.size();
        if (length == 1) {
            return nums[0];
        } else if (length == 2) {
            return max(nums[0], nums[1]);
        }
        return max(robRange(nums, 0, length - 2), robRange(nums, 1, length - 1));
    }
};

