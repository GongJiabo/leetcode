class Solution {
public:
    int lengthOfLongestSubstring(string s)
	{
		int n = s.length();
		int temp,max = 0;
		int i = 0, j, k;
		while (i < n)
		{
			temp = 1;
			for (j = i + 1; j < n; j++)
			{
				int first_show = search_repeat(s, i, j, s[j]);
				if (first_show != -1)
				{
				i = first_show + 1;
				break;
				}
				temp++;
			}
			if (temp >= max) max = temp;
			if (j >= n) break;
		}
        return max;
    }
    int search_repeat(string &str, int begin, int end, char c)
    {
		for (int i = begin; i < end; i++)
		{
			if (str[i] == c)	return i;
		}
		return -1;
    }
};