class Solution {
public:
void nextPermutation(vector<int>& nums) 
{
	int n = nums.size();
	int i, j;
	int swp;
	for (i = n - 2; i >= 0; i--)
	{
		if (nums[i] < nums[i + 1])
		{
			//找到末尾有序数字中刚比nums[i]打的那个数字并交换
			int key = nums[i];
			int sub_min = nums[i + 1] - key;
			for (j = i + 1; j < n; j++)
			{
				int sub = nums[j] - key;
				if (sub > 0)
				{
					if (sub <= sub_min)
					{
						sub_min = sub;
						swp = j;
					}
				}
			}
			break;
		}
	}
	if (i != -1)
	{
		swap(nums[i], nums[swp]);
		sort(nums.begin() + i + 1 , nums.end());
	}
	else
		sort(nums.begin(), nums.end());
}

void swap(int &a, int&b)
{
	int temp = a;
	a = b;
	b = temp;
}
};