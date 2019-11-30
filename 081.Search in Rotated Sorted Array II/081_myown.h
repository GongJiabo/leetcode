//直接遍历
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
            if(nums[i]==target) return true;
        return false;
    }
};

//二分查找
class Solution {
public:
  	  bool search(vector<int>& nums, int target) 
    {
        if(nums.empty()) return false;
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while(left <= right)
        {
			mid = (left + right) / 2;
            if(nums[mid] == target) return true;
            //add judgement
            if (nums[left] == nums[mid])
            {
                left++;
                continue;
            }
			else if (nums[mid] == nums[right])
			{
				right--;
				continue;
			}
            //位于右边
            if(nums[mid] < nums[right])   
            {
                //target <= nums[right],说明target位于右半部分
                //nums[mid] < target,说明target位于右半部分的右半部分,left = mid + 1
                if(target <= nums[right] && target > nums[mid])
                    left = mid + 1;
                //target > nums[right]，说明颠倒了顺序，target位于左半部分
                //targget <= nums[mid]，说明target位于左半部分的右部分
                else 
                    right = mid - 1;
            }     
             //mid位于左半部分
            else if (nums[mid] >= nums[right]) 
            {
                //nums[left] <= target,说明target位于左半部分
                //target < nums[mid],说明target位于左半部分的左半部分,right = mid - 1
                if (nums[left] <= target && target < nums[mid]) 
                    right = mid - 1;
                //nums[left] > target,说明target位于右半部分,left = mid + 1
                //target > nums[mid],说明target位于左半部分的右半部分,left = mid + 1
                else 
                    left = mid + 1;
            }
        }
        return false;
    }
};