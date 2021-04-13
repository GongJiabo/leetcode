// https://leetcode-cn.com/problems/wiggle-subsequence/solution/bai-dong-xu-lie-by-leetcode-solution-yh2m/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }
        int up = 1, down = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up = max(up, down + 1);
            } else if (nums[i] < nums[i - 1]) {
                down = max(up + 1, down);
            }
        }
        return max(up, down);
    }
};