class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) 
	{
		bool result = false;
		int row = matrix.size();
        if(row==0) return false;
		//
        int col = matrix[0].size();
        if(col==0) return false;
        //
		int i,j;
		for (i = 0; i < row; i++)
		{
			if (matrix[i][0] <= target && matrix[i][col-1] >= target)
				break;
		}
        if(i>=row) i--;
        if(matrix[row-1][col-1]>=target)
		    result = findinRow(matrix[i],target);
		return result;
	}
	bool findinRow(vector<int>& Row,int target)
	{
		// 二分查找
		bool res = false;
		int begin = 0;
		int end = Row.size()-1;
		while (begin <= end)
		{
			int mid = (begin + end) / 2;
			if (Row[mid] == target)
			{
				res = true;
				break;
			}
			else if (Row[mid] > target)
				end = mid-1;
			else if (Row[mid] < target)
				begin = mid+1;
		}
		return res;
    }
};