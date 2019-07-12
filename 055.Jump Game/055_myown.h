// 1.动态规划
class Solution {
public:
		bool canJump(vector<int>& nums) 
	{
		int n = nums.size();
		if (n <= 1) return	true;
		if (nums[0] == 0) return false;
		vector<bool> judge(n);
        //bool *judge = new bool[n];
		judge[0] = true;
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				int num = nums[j];
				if ((num + j) >= i && judge[j] == true)
				{
					judge[i]=true;
					break;
				}
			}
		}
		return judge[n-1];

	}
};

// 2.̰贪心法
class Solution {
public:
	bool canJump(vector<int>& nums) 
	{
		int n = nums.size();
		if (n <= 1) return	true;
		if (nums[0] == 0) return false;
		int lastpos = n - 1;
		for (int i = lastpos - 1; i >= 0; i--)
		{
			if (nums[i] + i >= lastpos)
				lastpos = i;
		}
		return lastpos == 0;
	}
};	