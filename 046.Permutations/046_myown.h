/*
 *    The algroithm - Take each element in array to the first place.
 *
 *    For example: 
 *    
 *         0) initalization 
 * 
 *             pos = 0
 *             [1, 2, 3]   
 *
 *         1) take each element into the first place, 
 *
 *             pos = 1
 *             [1, 2, 3]  ==>  [2, 1, 3] , [3, 1, 2] 
 *
 *             then we have total 3 answers
 *             [1, 2, 3],  [2, 1, 3] , [3, 1, 2] 
 *            
 *         2) take each element into the "first place" -- pos 
 *
 *             pos = 2
 *             [1, 2, 3]  ==>  [1, 3, 2]
 *             [2, 1, 3]  ==>  [2, 3, 1]
 *             [3, 1, 2]  ==>  [3, 2, 1] 
 *
 *             then we have total 6 answers
 *             [1, 2, 3],  [2, 1, 3] , [3, 1, 2], [1, 3, 2], [2, 3, 1], [3, 2, 1]
 *
 *          3) pos = 3 which greater than length of array, return.
 *
 */

class Solution {
public:
void dfs(vector<int>& nums, map<int, int>& selected, int index,vector<int>& oneresult, vector<vector<int>>&result)
{
	if (index == nums.size())							//排列完一次
	{
		result.push_back(oneresult);					//本次结果加入最终结果
		return;
	}
	for (int i = 0; i < nums.size(); i++)				//对所有数据进行遍历
	{
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

vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> result;
        map<int, int> selected;
        vector<int> oneresult;
        dfs(nums, selected, 0, oneresult, result);
        return result;
    }
};  