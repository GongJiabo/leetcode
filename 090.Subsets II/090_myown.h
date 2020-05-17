//Method 1
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
		//去重！！！排序后前后两个元素相同，则跳过
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

//Method 2
class Solution {
public:
vector<vector<int>> result;
void func(vector<int>& temp, int index, vector<int>& nums)
{
	result.push_back(temp);
    if(index<nums.size())
	{
		for(int i =index;i<nums.size();i++)
        {
            //剪枝 去重！！！必须先排序
            if(i>index && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            func(temp,i+1,nums);
            temp.pop_back();
        }
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