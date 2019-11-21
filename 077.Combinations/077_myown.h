class Solution {
private:
    int n;
    int k;
public:
	vector<vector<int>> combine(int n, int k) 
	{
        this->n=n;
        this->k=k;
		vector<vector<int>> res;
		backtrace(1, vector<int>{}, res);
		return res;
    }

	void backtrace(int first, vector<int> curr,vector<vector<int>> & res)
	{
		if (curr.size() == k)
		{
			res.push_back(curr);
			return;
		}
		//
		for (int i = first; i < n + 1; i++)
		{
			curr.push_back(i);
			//trace
			backtrace(i + 1, curr, res);
			//traceback
			curr.pop_back();
		}
    }
};