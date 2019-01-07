class Solution {
public:
int removeElement(vector<int>& nums, int val) 
{
        int n=nums.size();
       for (int i = 0; i < n;)
        {
            if (nums[i] == val) std::swap(nums[i], nums[--n]);
            else ++i;
        }
        return n;
}
};