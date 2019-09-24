class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) 
	{
		int n1 = matrix.size();
		int n2 = matrix[0].size();
		set<int> row, col;
		//将0所在的行列存储
		for (int i = 0; i < n1; i++)
		{
			for (int j = 0; j < n2; j++)
			{
				if (matrix[i][j] == 0)
				{
					row.insert(i);
					col.insert(j);
				}
			}
		}
		//置零
		for (auto it1 = row.begin(); it1 != row.end(); it1++)
		{
			for (int j = 0; j < n2; j++)
				matrix[*it1][j] = 0;
		}
		for (auto it2 = col.begin(); it2 != col.end(); it2++)
		{
			for (int i = 0; i < n1; i++)
				matrix[i][*it2] = 0;
		}

    }
};