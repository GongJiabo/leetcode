vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> res;
	if (nums.size() < 3) return res;
	sort(nums.begin(), nums.end());
	int n = nums.size();
	//
	for (int i = 0; i < n - 2 , nums[i] <= 0; i++)
	{
		int j = i + 1;
		int k = n - 1;
		while (j < k )
		{
			vector<int> arr;
			if (nums[j] + nums[k] == -nums[i])
			{
				arr = { nums[i], nums[j], nums[k] };
				res.push_back(arr);
				while (nums[k] == nums[k - 1]) k--;
				while (nums[j] == nums[j + 1]) j++;
				j++;
				k--;
			}
			else if (nums[j] + nums[k] > -nums[i])
			{
				while (nums[k] == nums[k - 1]) k--;
				k--;
			}
			else if (nums[j] + nums[k] < -nums[i])
			{
				while (nums[j] == nums[j + 1]) j++;
				j++;
			}	
		}
		while (nums[i] == nums[i + 1]) i++;
	}
	//sort(res.begin(), res.end());
	//if (res.size()>1) res.erase(unique(res.begin(), res.end()), res.end());
	return res;
}