class Solution {
public:
int removeElement(vector<int>& nums, int val) 
{
	vector<int> temp;
	for (auto it = nums.begin(); it != nums.end(); it++)
	{
		if (*it == val) continue;
		temp.push_back(*it);
	}
	nums.clear();
	nums = temp;
	return nums.size();
}
};