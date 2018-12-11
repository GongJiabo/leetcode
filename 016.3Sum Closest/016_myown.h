#include <vector>
#include <algorithm>
using std::vector; 

class Solution {
public:
int threeSumClosest(vector<int>& nums, int target)
{
	sort(nums.begin(), nums.end());
	int min = INT_MAX, sum = 0, temp = 0;
	for (auto iter = nums.cbegin(); iter != nums.cend(); ++iter)
	{
		for (auto beg = next(iter), e = prev(nums.cend()); beg < e; temp>target ? --e : ++beg)
		{
			if ((temp = (*iter + *beg + *e))== target)  return target;
			else if (abs(temp - target) < min)
			{
				sum = temp;
				min = abs(temp - target);
			}
		}
	}
	return sum;
}
};