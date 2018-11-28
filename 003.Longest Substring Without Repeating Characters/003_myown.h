//耗时太长！！！！！！！！！！！leetcode执行时间超出范围
//时间复杂度到达O(n三次方)
//算法easy

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
    	int max = n;
    	int i, j, k;
    	bool judge;
    	for (i = n ; i > 0; i--)  //滑动窗口大小
		{			  
	    	int times = n - i;
	    	for (j = 0; j <= times; j++)
	    	{
			    judge = true;
			    for (k = j + 1; k < i + j; k++)
			    {
				    if (s.substr(k, i + j - k).find(s[k-1]) != string::npos)
				    {
					judge = false;
					break;
				    }
			    }
			if (k >= i + j) break;
		    }
		    if (judge)
		    {
			max = i;
			break;
		    }
	    }
        return max;
    }
};