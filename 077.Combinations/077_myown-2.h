#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution
{
private:
	vector<vector<int>> res;
public:
	void findcombination(int n, int k, int start, vector<int> &c)
	{
		if (c.size() == k)
		{
			res.push_back(c);
			return;
		}
		else
		{
			for (int i = start; i <= n - (k-c.size()) + 1; i++)
			{
				c.push_back(i);
				findcombination(n, k, i + 1, c);
				c.pop_back();
			}
		}
	}

	vector<vector<int>> combine(int n, int k)
	{
		res.clear();
		if (n <= 0 || k <= 0 || k > n)
			return res;
		//
		vector<int> c;
		findcombination(n, k, 1, c);
		return res;
	}
};
