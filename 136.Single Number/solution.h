// 1、位运算
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto e: nums) ret ^= e;
        return ret;
    }
};

// 2、排序
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1)            //特判
        	return *nums.begin();
        sort(nums.begin(), nums.end());   //排个序
        vector<int>::iterator itB = nums.begin(), itE = nums.end();
        while(itB != itE){               //依次遍历
            if(*itB != *(itB + 1))
            return *itB;
            ++itB;
            ++itB;
        }
        return 0;
    }
};