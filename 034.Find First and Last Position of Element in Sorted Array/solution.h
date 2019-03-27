class Solution {
public:
    int left_bound(vector<int>& nums, int target)
    {
        int beg =  0;
        int end = nums.size()-1;
        int mid = 0;
        while(beg <= end)
        {
            mid = beg + (end-beg)/2;
            if(target == nums[mid])
            {
                if(mid == 0 || nums[mid-1] < target)
                    return mid;
                end = mid -1;
            }
            else if(target < nums[mid])
            {
                end = mid-1;
            }
            else if(target > nums[mid])
            {
                beg  = mid+1;
            }
        }
        return -1;
    }
    
    int right_bound(vector<int>& nums, int target)
    {
        int beg =  0;
        int end = nums.size()-1;
        int mid = 0;
        while(beg <= end)
        {
            mid = beg + (end-beg)/2;
            if(target == nums[mid])
            {
                if(mid == nums.size()-1 || nums[mid+1] > target)
                    return mid;
                beg = mid + 1;
            }
            else if(target < nums[mid])
            {
                end = mid-1;
            }
            else if(target > nums[mid])
            {
                beg  = mid+1;
            }
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = left_bound(nums, target);
        
        int right = right_bound(nums, target);

        
        return vector<int>{left, right}; 
    }
};