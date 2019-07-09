// 1. 暴力解法
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
	{
		int maxs = -999999;
		int n = nums.size();
        if (n == 1) return nums[0];
        //
		int i, j;
		for (i = 0; i < n; i++)
		{
			int sum = nums[i];
			j = i+1;
			while(j<n)
			{
				sum += nums[j];
				j++;
				if (sum > maxs) maxs = sum;
			}
            if (nums[i] > maxs) maxs = nums[i];
		}
		return maxs;
    }

};

// 2. DP
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        int sum=0;
        int res=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            sum=max(sum+nums[i],nums[i]);
            res=max(res,sum);
        }
        return res;
    }
};


