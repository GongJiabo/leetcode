#include<iostream>
#include<vector>
#include<string>
#include <string>
#include <algorithm> 

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) 
{
	vector<vector<int>> res;
	int n = nums.size();
	for (int i = 0; i < n-2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (nums[i] + nums[j] + nums[k] == 0)
				{
					vector<int> arr;
					bool tag = true;
					arr.push_back(nums[i]);
					arr.push_back(nums[j]);
					arr.push_back(nums[k]);
					sort(arr.begin(),arr.end());
					for (int s = 0; s < res.size(); s++)
					{
						if (arr == res[s])
						{
							tag = false;
							break;
						}
					}
					if (tag) res.push_back(arr);
					else continue;
				}
			}
		}
	}
	return res;
}


int main()
{

	vector<int> nums{ -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> result = threeSum(nums);
	
	system("pause");
	return 0;
}