class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> myset(nums1.begin(),nums1.end());
        set<int> sres;
        for(int i=0;i<nums2.size();i++)
        {
            if(myset.find(nums2[i])!=myset.end())
                sres.insert(nums2[i]);
        }
        vector<int> vres(sres.begin(),sres.end());
        return vres;
    }
};