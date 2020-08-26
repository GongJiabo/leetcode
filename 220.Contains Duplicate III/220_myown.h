class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        int n=nums.size();
        set<long long> record;
        for(int i=0;i<n;i++)
        {
            if(record.lower_bound((long long)nums[i]-(long long)t)!=record.end() &&   
            //存在差值小于t的下界
            *record.lower_bound((long long)nums[i]-(long long)t)<=(long long)nums[i]+(long long)t)          
                return true;
            //
            record.insert(nums[i]);
            //
            if(record.size()==k+1)
                record.erase(nums[i-k]);
        }
        return false;
    }
};