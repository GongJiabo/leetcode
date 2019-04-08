class Solution {
public:
	void compute(int start, int target, vector<int> &candidates, vector<int> &solution, vector<vector<int>> &result)
	{
		if (target < 0) return;
		if (target == 0)
		{
			result.push_back(solution);
			return;
		}
		for (int i = start; i < candidates.size(); i++)
		{
			//去重
			int n = candidates[i];
			if (i > start && candidates[i] == candidates[i - 1])
				continue;
			solution.push_back(n);
			compute(i + 1, target - n, candidates, solution, result);
			solution.pop_back();
		}
	}
	vector<vector<int> > combinationSum2(vector<int> &candidates, int target)
	{
		vector< vector<int> > result;
		if (candidates.size() <= 0) {
			return result;
		}
		sort(candidates.begin(), candidates.end());

		vector<int> solution;
		compute(0, target, candidates, solution, result);

		return result;
	}
};