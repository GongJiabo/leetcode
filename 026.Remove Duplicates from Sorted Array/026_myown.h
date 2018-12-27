//////////one
class Solution {
public:
   int removeDuplicates(vector<int>& nums) {
	if (nums.size() == 0) return 0;
	int temp = nums[0];
	int sum = 1;
	for (int i = 1; i<nums.size(); i++)
	{
		if (nums[i] == temp)
		{
			nums.erase(nums.begin() + i);
			i--;
			continue;
		}
		temp = nums[i];
		sum++;
	}
	return sum;
}
};


//////////two	
class Solution {
public:
   int removeDuplicates(vector<int>& nums)
   {
    if(nums.size()==0) return 0;
    int i=0; //慢指针
    for(int j=1;j<nums.size();j++)
    {
        if(nums[j]!=nums[i])
        {
            i++;
            nums[i]=nums[j];
        }
    }
       return i+1;
    }
};