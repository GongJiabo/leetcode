//1.暴力法(超出时间限制)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n =nums.size();
        if(n<1) return 0;
        int sum, length=n+1;
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
            {
                sum=0;
                for(int k=i;k<=j;k++)
                    sum+=nums[k];
                if(sum>=s)
                    length=min(length, j-i+1);
            }
        if(length == n+1) return 0;
        return length;
    }
};

//2.滑动窗口
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r =-1; //nums[r...l]为我们的滑动窗口
        int sum = 0;
        int res = nums.size() + 1;
        //
        while( l < nums.size() )
        {
            //滑动窗口
            if( r+1 < nums.size() && sum < s)
            {
                r++;
                sum += nums[r];
            }
            else
            {
                sum -= nums[l];
                l++;
            }
            //
            if( sum >= s)
                res = min(res, r-l+1);
        }

        if(res == nums.size()+1)
            return 0;
        return res;
    }
};