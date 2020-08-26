class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_set<int> record;
        //
        for (int i = 0; i < n; i++)
        {
            if (record.find(nums[i]) != record.end())
                return true;
            record.insert(nums[i]);
        }
        return false;

    }
};