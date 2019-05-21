class Solution {
public:
int firstMissingPositive(vector<int>& nums)
{
    if(nums.size()==0) return 1;
    if(nums.size()==1)
    {
        if(nums[0]==1) return 2;
        else return 1; 
    }
    //
	sort(nums.begin(),nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] < 1) continue;
		if (nums[i] == 1) 
		{
			while (i<nums.size()-1)
			{
				if (nums[i] == nums[i + 1] - 1) i++;
                else if (nums[i]==nums[i+1]) i++;
				else return nums[i] + 1;
			}
			if (i == nums.size() - 1) return *(nums.end()-1) + 1;
		}
		else return 1;
	}
	return 1;
}
};