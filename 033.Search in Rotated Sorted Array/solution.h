//pezy
class Solution {
public:
    int search(int A[], int n, int target) {
        for (int i = 0, j = n-1; i <= j; )
        {
            int m = (i + j) >> 1;
            if (target == A[m]) return m;
            else if ((A[i] <= target && target < A[m]) || (A[m] < A[i] && (target < A[m] || A[i] <= target))) j = m - 1;
            else if ((A[m] < target && target <= A[j]) || (A[j] < A[m] && (target <= A[j] || A[m] < target))) i = m + 1;
            else break;
        }
        return -1;
    }
};

//leetcode
//需要在经典二分查找的基础上增加对mid和target位于左半部分还是位于右半部分的判断逻辑
//mid左，target右，left = mid + 1
//mid左，target左，target < nums[mid],right = mid - 1
//nums[mid] < target,left = mid + 1

//mid右，target左，right = mid - 1
//mid右，target右，target < nums[mid],right = mid - 1
//nums[mid] < target,left = mid + 1
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left)>>1);
            if (nums[mid] == target) {
                return mid;
            }
            //mid位于右半部分
            if (nums[mid] < nums[right]) {
                //target <= nums[right],说明target位于右半部分
                //nums[mid] < target,说明target位于右半部分的右半部分,left = mid + 1
                if (target <= nums[right] && nums[mid] < target) {
                    left = mid + 1;
                }
                //target > nums[right],说明target位于左半部分,right = mid - 1
                //target < nums[mid],说明target位于右半部分的左半部分,right = mid - 1
                else {
                    right = mid - 1;
                }
            }
            //mid位于左半部分
            else if (nums[mid] >= nums[right]) {
                //nums[left] <= target,说明target位于左半部分
                //target < nums[mid],说明target位于左半部分的左半部分,right = mid - 1
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                //nums[left] > target,说明target位于右半部分,left = mid + 1
                //target > nums[mid],说明target位于左半部分的右半部分,left = mid + 1
                else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};
