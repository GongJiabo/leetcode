class Solution {
public:
    string longestPalindrome(string s) {
    int n = s.length();
    if(n==0) return string("");
    if(n==1) return s;
	int max_len1 = 1, max_len2 = 1;
	int start1 = 0, start2 = 0;
	int max, start;
	int i, j;
	//长为偶数时
	for (i = 0; i < n; i++)
	{
		int temp_len = 1;
		int temp_start = 0;
		j = 0;
		if (s[i] == s[i + 1])
		{
			while (true)
			{
				j++;
				if (i + j + 1 >= n || i - j < 0)
				{
					temp_len = j * 2;
					temp_start = i;
					break;
				}
				if (s[i - j] != s[i + j + 1])  
				{
					temp_len = j * 2;
					temp_start = i;
					break;
				}
				
			}
		}
		if (temp_len >= max_len1)
		{
			start1 = temp_start;
			max_len1 = temp_len;
		}
	}
	//长为奇数
	for (int i = 1; i < n; i++)
	{
		int temp_len = 1;
		int temp_start = 0;
		j = 1;
		if (s[i - 1] == s[i + 1])
		{
			while (true)
			{
				j++;
				if (i + j >= n || i  - j < 0)
				{
					temp_len = j * 2 - 1;
					temp_start = i;
					break;
				}
				if (s[i - j] != s[i + j])
				{
					temp_len = j * 2 - 1;
					temp_start = i;
					break;
				}

			}			
		}
		if (temp_len >= max_len2)
		{
			start2 = temp_start;
			max_len2 = temp_len;
		}
	}
	if (max_len2 > max_len1)
	{
		max = max_len2;
		start = start2;
		return s.substr(start - max / 2 , max);
	}
	else
	{
		max = max_len1;
		start = start1;
		return s.substr(start - max / 2 + 1, max) ;
	}
        
    }
};