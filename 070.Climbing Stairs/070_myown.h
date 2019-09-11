// 1. 递归实现动态规划，超出时间限制
class Solution {
public:
	int climbStairs(int n)
	{
		if (n == 1)
			return 1;
		else if (n == 2)
			return 2;
		else
			return climbStairs(n - 1) + climbStairs(n - 2);
	}
};

// 2.循环实现动态规划，用空间换时间
class Solution {
public:
	int climbStairs(int n)
	{
		int *f = new int[n];
		if (n == 1)
			return 1;
		else if (n == 2)
			return 2;
		else
		{
			f[0] = 1;
			f[1] = 2;
			for (int i = 2; i <  n; i++)
				f[i] = f[i - 1] + f[i - 2];
		}
		int res = f[n-1];
		delete[]f;
		return res;
	}
};