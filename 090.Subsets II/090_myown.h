class Solution {
public:
vector<vector<int>> result;
void func(vector<int>& temp, int index, vector<int>& nums)
{
	if (index == nums.size())
		result.push_back(temp);
	else
	{
		temp.push_back(nums[index]);
		func(temp, index + 1, nums);
		temp.pop_back();
		while (index + 1 < nums.size() && nums[index] == nums[index + 1])
			index++;
		func(temp, index + 1, nums);
	}
}
vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
	if (nums.size() == 0)
		return { {} };
	//对输入数组排序
	sort(nums.begin(), nums.end());
	vector<int> temp;
	func(temp, 0, nums);
	return result;
}


};