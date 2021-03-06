//循环遍历容器，时间复杂度为O(n)
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int i;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]==target) 
                return i;
        }
        return -1;
    }
};

//二分查找
class Solution {
public:
int search(vector<int>& nums, int target)
{
	int n = nums.size();
	if (n == 0) return -1;
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] < nums[right]) {
			if (nums[mid] < target && nums[right] >= target) left = mid + 1;
			else right = mid - 1;
		}
		else {
			if (nums[left] <= target && nums[mid] > target) right = mid - 1;
			else left = mid + 1;
		}
	}
	return -1;
}
};