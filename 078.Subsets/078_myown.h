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


class Solution
{
private:
	vector<vector<int>> res;
public:
	void findsub(vector<int>& nums, int index, vector<int>& c)
	{
		res.push_back(c);
		//
		if (index < nums.size())
		{
			for (int i = index; i < nums.size(); i++)
			{
				c.push_back(nums[i]);
				findsub(nums, i + 1, c);
				c.pop_back();
			}
		}
		return;
	}

	vector<vector<int>> subsets(vector<int>& nums)
	{
		res.clear();
		if (nums.size() <= 0) return res;
		//
		vector<int> c{};
		findsub(nums, 0, c);
		return res;
	}
};
