//1. 排序后去倒数第k个元素
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};

//2. 每次寻找最大的元素放在末尾
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<k;i++)
        {
            int max=nums[0];
            int imax=0;
            for(int p=0;p<n;p++)
            {
                if(max<nums[p])
                {
                    max=nums[p];
                    imax=p;
                }
            }
            swap(nums[imax],nums[--n]);
        }
        return nums[n];
    }
};
