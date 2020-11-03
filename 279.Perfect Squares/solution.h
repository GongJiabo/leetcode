//1. 动态规划
int numSquares(int n)
{
    vector<int> result(n+1, 0x7FFFFFFF); // 每个数的最优解都存在result数组里
    result[0] = 0;
    for (int i = 1; i <= n; i++){
        for(int j = 1; i-j*j >= 0 ; j++) {  // 观察比N小的数，且符合N = IxI + N'的数值
            result[i] = min(result[i], result[i-j*j] + 1); // 把最优解（最小值）+ 1 写入result
        }
    }
    return result[n];
}
//
class Solution 
{
public:
    int numSquares(int n) 
    {
        vector<int> dp(n+1, n);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = sqrt(i); j > 0; --j)
            {
                dp[i] = min(dp[i], dp[i-j*j] + 1);
            }
        }
        return dp[n];
    }