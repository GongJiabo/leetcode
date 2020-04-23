//1. 逐个插入
//2. 直接在末尾插入后排序
//3. 使用STL-multiset
#include<algorithm>

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++)
            nums1[i+m]=nums2[i];
        std::sort(nums1.begin(),nums1.end());

    }
};



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++)
        {   
            //找到nums2[i]在nums1中的位置j
            int j=0;
            while(j<i+m && nums1[j]<nums2[i]) 
                j++;
            int k=nums1.size()-1;
            //后移
            while(k>j)
            {
                nums1[k]=nums1[k-1];
                k--;
            }
            nums1[j]=nums2[i];
        }

    }
};