class Solution {
public:
int strStr(string haystack, string needle) 
{
	int n1 = haystack.size();
	int n2 = needle.size();
	if (n2 == 0) return 0;
	int i, j;
	for (i = 0, j = 0; i < n1; i++)
	{
		if (haystack[i] == needle[j])
		{
			int k = i;
			for (; j < n2; k++, j++)
			{
				if (haystack[k] != needle[j])
				{
					j = 0;
					break;
				}
			}
		}
		if (j == n2) return i;
	}
	return -1;
}

};