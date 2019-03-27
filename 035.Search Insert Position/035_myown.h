class Solution {
public:
int searchInsert(vector<int>& nums, int target)
{
	int i = 0;
	for (i = 0; i<nums.size() - 1; i++)
	{
		if (nums[i] == target) return i;
        else if (nums[i] > target) return 0;
		else
		{
			if (nums[i + 1] == target) return i + 1;
			else if (nums[i] <target && nums[i + 1]>target) return i+1;
		}
	}
	if (nums[i]<target) return (i + 1);
    return 0;
}
};