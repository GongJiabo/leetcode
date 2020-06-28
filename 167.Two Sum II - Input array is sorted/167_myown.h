//1. 暴力法，两重循环，时间超限
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                if(numbers[i]+numbers[j]==target)
                {
                    vector<int> res{i+1,j+1};
                    return res;
                }
            }
        return {};
    }
};


//2. 双指针法
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        assert(n>=2);
        int i=0,j=n-1;
        while(i<j)
        {
            if(target==(numbers[i]+numbers[j]))
            {
                vector<int> res{i+1,j+1};
                return res;
            }
            else if(target<(numbers[i]+numbers[j]))
                j--;
            else 
                i++;
        };
        return {};
    }
};