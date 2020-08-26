//1. map 哈希，判断key值是否大于1
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_map <int,int>mp;
        for(int i:nums)
        {
            mp[i]++;  //i对应的value值++
            if(mp[i]>1)     return true;    //i对应的value值大于1，则说明存在重复元素  
        }
        return false;
    }
};

//2. 利用集合，与原数组比较大小
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

         return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size(); 
         //如果原数组的大小>集合的大小，则说明存在重复元素
    }
};

//3. 排序，比较前后两个元素是否相等，来判断是否存在重复元素
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

       sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
                return true;
        } 
        return false;
    }
};

 
 