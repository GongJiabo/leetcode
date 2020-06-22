//1. 时间复杂度O(n)，创建临时数组存储非零元素
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i,j;
        j=0;
        vector<int> temp(n,0);
        for(i=0;i<n;i++)
            if(nums[i]!=0)
                temp[j++]=nums[i];

        for(i=0;i<n;i++)
            nums[i]=temp[i];
    }
};

//2. 在原数组上操作，对后面的元素赋值
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int n = nums.size();
        int i,j;
        j=0;
        vector<int> temp(n,0);
        for(i=0;i<n;i++)
        {
            if(nums[i]!=0)
                nums[j++]=nums[i];
        }
        for(;j<n;j++)
            nums[j]=0;
    }
};

//3. 原数组上，交换元素
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int n = nums.size();
        int i,j;
        j=0;
        vector<int> temp(n,0);
        for(i=0;i<n;i++)
        {
            if(nums[i]!=0)
                if(i!=j)
                    swap(nums[j++],nums[i]);
                else 
                    j++;
        }
    }
};