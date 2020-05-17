class Solution
{
private:
	vector<vector<int>> res;
	vector<bool> used;
public:
	vector<vector<int>> permute(vector<int>& nums)
	{
		res.clear();
		if (nums.size() == 0) return res;
		//
		used = vector<bool>(nums.size(), false);
		Perm(nums, 0, {});
		return res;

	}
	void Perm(vector<int>& nums, int index, vector<int> temp)
	{
		if (index == nums.size())
		{
			res.push_back(temp);
			return;
		}
		else
		{
			for (int i = 0; i < nums.size(); i++)
			{
				if (!used[i])
				{
					temp.push_back(nums[i]);
					used[i] = true;
					Perm(nums, index + 1, temp);
					temp.pop_back();
					used[i] = false;
				}
			}
		}
		return;
	}
};