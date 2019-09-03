class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
        if(m==0) return 0;
		unsigned int nums[m][n];
        //设置第一个位置的值,很关键
        nums[0][0] = obstacleGrid[0][0] == 0?1:0;
        //注意初始值并不是简单的1或0,与其前一个值有关,一直关联到obs[0][0]
        for(int i=1;i<m;i++)
             nums[i][0] = obstacleGrid[i][0] == 0?nums[i-1][0]:0;
        for(int j=1;j<n;j++)
             nums[0][j] =  obstacleGrid[0][j] == 0?nums[0][j-1]:0;
        //
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                 nums[i][j] =  obstacleGrid[i][j] == 1?0:nums[i-1][j]+nums[i][j-1];   
        //
        return nums[m-1][n-1];
    }
};