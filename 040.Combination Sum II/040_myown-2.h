class Solution
{
private:
	vector<vector<int>> res;
public:

	vector<vector<int>> findcomb(vector<int>& candidates, int target, int start, vector<int>& c)
	{
		if (target == 0)
		{
			res.push_back(c);
			return res;
		}
		if (target < 0) return res;
		else 
		{
			for (int i = start; i < candidates.size(); i++)
			{
				if (target > 0)
				{
					if (i > start && candidates[i] == candidates[i - 1]) continue;
					c.push_back(candidates[i]);
					findcomb(candidates, target - candidates[i], i+1, c);
					c.pop_back();
				}
			}
		}
		return res;
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		res.clear();
		if (candidates.size() == 0) return res;
		//
		sort(candidates.begin(), candidates.end());
		vector<int> c;
		findcomb(candidates, target, 0, c);
		return res;
	}
	
};