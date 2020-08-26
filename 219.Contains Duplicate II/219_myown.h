//利用滑动窗口
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        unordered_set<int> record;
        //
        for (int i = 0; i < n; i++)
        {
            if (record.find(nums[i]) != record.end())
                return true;
            record.insert(nums[i]);
            //滑动窗口
            if (record.size() == k + 1)
                record.erase(nums[i - k]);
        }
        return false;
    }
};