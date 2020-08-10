//1. 利用了map初始值为0的特点
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mymap;
        vector<int> res;
        for(int i=0;i<nums1.size();i++)
            mymap[nums1[i]]++;
        for(int i=0;i<nums2.size();i++)
        {
            if(mymap[nums2[i]] > 0)
            {
                res.push_back(nums2[i]);
                mymap[nums2[i]]--;
            }
        }
        return res;
    }
};


//2. 
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mymap;
        vector<int> res;
        for(int i=0;i<nums1.size();i++)
        {   if(mymap.find(nums1[i])==mymap.end())
                mymap.insert(make_pair(nums1[i],1));
            else
                mymap[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(mymap.find(nums2[i])!=mymap.end() && mymap[nums2[i]] > 0)
            {
                res.push_back(nums2[i]);
                mymap[nums2[i]]--;
                if(mymap[nums2[i]]==0)
                    mymap.erase(nums2[i]);
            }
        }
        return res;
    }
};