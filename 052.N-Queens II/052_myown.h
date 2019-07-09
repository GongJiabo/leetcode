class Solution {
public:
    int totalNQueens(int n) {
        return solveNQueens(n).size();
    }
    vector<vector<string>> solveNQueens(int n)
	{
		vector<vector<string>> res;
		int *q = new int[n+1]();
		int count = 0;
		place(1, n, q, res);
		delete[]q;
		return res;
	}
	int find(int i, int k, int *q)
	{
		int j = 1;
		while (j < i)	//j=1~i是已经放置了皇后的行
		{
			//判断第j行的皇后是否在第k列上，或者(j,q[j])与(i,k)是否在对角线上
			if (q[j] == k || abs(j - i) == abs(q[j] - k)) return 0;
			j++;
		}
		return 1;
	}
	void place(int k, int n, int *q,vector<vector<string>> &sol)
	{
		int j;
		if (k > n)
		{
			vector<string> res = print(n, q);
			sol.push_back(res);
		}
		else
		{
			for (j = 1; j <= n; j++)
			{
				if (find(k, j, q))
				{
					q[k] = j;
					place(k + 1, n, q, sol);
				}
			}
		}
	}
	vector<string> print(int n, int *q)
	{
		int i, j;
		vector<string> res;
		for (i = 1; i <= n; i++)
		{
			string s = "";
			for (j = 1; j <= n; j++)
			{
				if (q[i] != j)
					s += ".";
				else
					s += "Q";
			}
			res.push_back(s);
		}
		return res;
	}
};