//pezy
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n<3) return n;
        int size{1};
        for (int i=2; i<n; ++i)
            if (A[i] != A[size] || A[i] != A[size-1])
                A[++size] = A[i];
        return ++size;
    }
};


//from leetcode dexin
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
        {
            return n;
        }
        int sp = 1;
        for(int fp = 2; fp < n; fp++)
        {
            if(nums[fp] != nums[sp - 1])
            {
                nums[++sp] = nums[fp];
            }
        }
        return sp + 1;
    }
};

