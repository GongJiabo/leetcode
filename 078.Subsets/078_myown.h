class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums)
	{
		int n = nums.size();
		vector<vector<int>> res;
		for(int i = n; i >= 0; i--)
			backtrace(vector<int>{}, res, i, n, nums);
		return res;
	}

	void backtrace(vector<int> curr, vector<vector<int>> & res, int  &round, int  n, vector<int> &nums)
	{
		if (curr.size() == round)
		{
			res.push_back(curr);
			return;
		}
		for (int i = n - 1; i >= 0; i--)
		{
			curr.push_back(nums[i]);
			backtrace(curr, res, round, --n, nums);
			curr.pop_back();
		}
		//
	}

};