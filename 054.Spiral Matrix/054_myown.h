class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
	{
		vector<int> res;
        if(matrix.empty()) return res;
		//m行,n列
		int m = matrix.size();
		int n = matrix[0].size();
		//
		if (m == 0) return matrix[0];
        //右下左上右下...设定边界，从左上开始
		int left = 0, up = 0, right = n - 1, down = m - 1;
		while (true)
		{
			//向右
			for (int i = left; i <= right; i++) res.push_back(matrix[up][i]);
			if (++up > down) break;
			//向下
			for (int i = up; i <= down; i++) res.push_back(matrix[i][right]);
			if (--right < left) break;
			//向左
			for (int i = right; i >= left; i--) res.push_back(matrix[down][i]);
			if (--down < up)break;
			//向上
			for (int i = down; i >= up; i--) 
				res.push_back(matrix[i][left]);
			if (++left > right) break;
		}
		return res;
		
    }
};