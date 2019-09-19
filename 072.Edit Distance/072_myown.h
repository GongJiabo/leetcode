class Solution {
public:
	int minDistance(string word1, string word2) 
	{
		int n1 = word1.size();
		int n2 = word2.size();
		int nmax = max(n1, n2);
		//创建动态规划的数组
		int **dp = new int*[n1+1];
		for (int i = 0; i <= n1; i++)
			dp[i] = new int[n2+1];
		for (int i = 0; i <= n1; i++)
		{
			for (int j = 0; j <= n2; j++)
				dp[i][j] = nmax;
		}
		//初始化边缘数据
		dp[0][0] = 0;
		for (int i = 0; i <= n2; i++)
			dp[0][i] = i;
		for (int i = 0; i <= n1; i++)
			dp[i][0] = i;
		//计算
		for (int i = 1; i <= n1; i++)
		{
			for (int j = 1; j <= n2; j++)
			{
				int flag = 0;
				if (word1[i-1] != word2[j-1])
					flag = 1;
				dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + flag));
				//dp[i-1][j]+1表示删掉字符串a最后一个字符a[i]
				//dp[i][j-1]+1表示给字符串添加b最后一个字符
				//dp[i-1][j-1]+flag表示改变,相同则不需操作次数,不同则需要,用flag记录
			}
		}
		int res = dp[n1][n2];
		for (int i = 0; i <= n1; i++)
			delete[]dp[i];
		delete[]dp;
		return res;
	}
};