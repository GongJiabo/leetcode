class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
{
	int n = nums.size();
	if (n == 0) return{};
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	//
	for (int i = 0; i < n; i++)
	{
		if (i>0 && nums[i] == nums[i - 1]) continue;
		int newtarget = target - nums[i];
		//化为三个数的和
		for (int j = i + 1; j < n; j++)
		{
			if (j > i + 1 && nums[j] == nums[j - 1]) continue;
			int newtarget2 = newtarget - nums[j];
			int p = j + 1, q = n - 1;
			// 化为两个数的和
			while (p < q)
			{
				if (nums[p] + nums[q] == newtarget2)
				{
					res.push_back({ nums[i], nums[j], nums[p], nums[q] });
					while (p < q && nums[p] == nums[p + 1]) p++;
					while (p < q && nums[q] == nums[q - 1]) q--;
					p++;
					q--;
				}
				else if ((nums[p] + nums[q] > newtarget2)) q--;
				else if ((nums[p] + nums[q] < newtarget2)) p++;
			}
		}
	}
	return res;
}
};