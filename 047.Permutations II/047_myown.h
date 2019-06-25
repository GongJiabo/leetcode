class Solution {
public:
	void dfs(vector<int>& nums, map<int, int>& selected, int index, vector<int>& oneresult, vector<vector<int>>&result)
	{
		if (index == nums.size())							//排列完一次
		{
			result.push_back(oneresult);					//本次结果加入最终结果
			return;
		}
		for (int i = 0; i < nums.size(); i++)				//对所有数据进行遍历
		{
            //*********************切支***********************//
			if (i > 0 && nums[i] == nums[i - 1] && selected[i - 1]) continue;

			if (selected[i] != 0)							//若已经选择过则跳过
				continue;
			//这里使用人工方式进行回溯完全是因为函数参数使用的是引用，
			//使用引用的方式是为了减少递归中参数复制导致时间的浪费。
			selected[i] = 1;								//添加选中标识
			oneresult.push_back(nums[i]);					//本元素加入本次结果中
			dfs(nums, selected, index + 1, oneresult, result);	//下一次遍历
			selected[i] = 0;								//清除选中标识
			oneresult.pop_back();							//本元素出本次结果
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums)
	{
        //先进行排序，便于切支
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		map<int, int> selected;
		vector<int> oneresult;
		dfs(nums, selected, 0, oneresult, result);
		return result;
	}
};

//核心语句在第13行，对重复的选择进行剪切