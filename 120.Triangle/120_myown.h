class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n < 1) return 0;
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = triangle[0][0];
        //
        for(int i=1;i<n;++i)
        {
            // 每行第一个元素一定是上一行的第一个元素的路径
            dp[i][0] = dp[i-1][0] + triangle[i][0];

            // 去除每行第一个和最后一个元素
            for(int j=1;j<i;++j)
            {
                dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]) + triangle[i][j];
            }

            // 最后一个元素
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};