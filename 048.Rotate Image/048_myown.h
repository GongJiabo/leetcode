class Solution {
public:
	void rotate(vector<vector<int>>& matrix)
	{
		int n = matrix.size();
		//先转置
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
				swap(matrix[i][j], matrix[j][i]);
		}
		//按列翻转
		for (int m = 0; m < n; m++)
		{
			for (int k = 0; k < n/2; k++)
			{
				swap(matrix[m][k], matrix[m][n - 1 - k]);
			}
		}
    }

	void swap(int &a, int &b)
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
};