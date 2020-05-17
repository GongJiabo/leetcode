class Solution
{
private:
	vector<vector<int>> res;

public:
	void findcomb(int k, int n, int index, vector<int>& c)
	{
		if (k == 0 && n == 0)
		{
			res.push_back(c);
			return;
		}
		else if (n < 0) return;
		else
		{
			for (int i = index; i < 10; i++)
			{
				c.push_back(i);
				findcomb(k - 1, n - i, i + 1, c);
				c.pop_back();
			}
		}
		return;
	}

	vector<vector<int>> combinationSum3(int k, int n)
	{
		res.clear();
		if (k <= 0 || n <= 0 || n > 45) return res;
		//
		vector<int> c;
		findcomb(k, n, 1, c);
		return res;
	}
};