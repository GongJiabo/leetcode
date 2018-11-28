class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
       int n = s.length();
    	int max = 0;
    	int i, j, k;
    	for (i = 0; i < n; i++)
    	{
		    int temp = 1;
		    for (j = i + 1; j < n; j++)
	    	{
			if (!search_repeat(s, i, j, s[j]))
		    	{
			    	temp ++;
		    	}
			else break;
	    	}
	    	if (temp >= max) max = temp;
    	}    
        return max;
    }
    bool search_repeat(string str, int begin, int end, char c)
    {
    	for (int i = begin; i < end; i++)
	    {
	    	if (str[i] == c)	return true;
	    }
    	return false;
    }
};