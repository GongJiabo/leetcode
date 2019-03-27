class Solution {
public:
vector<int> searchRange(vector<int>& nums, int target) 
{
    int p = -1;
	int a1 = -1, a2 = -1;
	for (int i = 0, j = nums.size(); i < j;)
	{
		int mid = (i + j) / 2;
		if (nums[mid] == target)
		{
			p = mid;
			break;
		}
		else if (nums[mid] > target)
		{
			if (j == mid) break;
			j = mid;
		}
		else
		{
			if (i == mid) break;
			i = mid;
		}
	}
	if (p == -1) return vector<int>{-1, -1};
	else
	{
		a1 = p;
		a2 = p;
		while (a1 > 0 && nums[a1 - 1] == target) a1--;
		while (a2+1 < nums.size() && nums[a2 + 1] == target) a2++;
		return vector<int>{a1, a2};
	}
}
};