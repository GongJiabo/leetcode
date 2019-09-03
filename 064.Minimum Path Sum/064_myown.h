class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
	{
		int m = grid.size();
		int n = grid[0].size();
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int left = j - 1 >= 0 ? grid[i][j - 1] : 0;
				int up = i - 1 >= 0 ? grid[i - 1][j] : 0;
				if (i == 0)
					grid[i][j] += left;
				else if (j == 0)
					grid[i][j] += up;
				else
					grid[i][j] += min(left, up);
			}
		}
		return grid[m-1][n-1];
	}
};