class Solution {
public:
int longestValidParentheses(string s) 
{
	int nmax = 0, start = 0;	
	int n = s.size();
	if (n < 2) return 0;
	stack<int> vc;
	for (int index = 0; index < n; index++)
	{
		if (s[index] == '(')
		{
			vc.push(index);
			continue;
		}
		else
		{
			if (vc.empty())
			{
				start = index + 1;
				continue;
			}
			else
			{
				vc.pop();
				nmax = vc.empty() ? max(nmax, index - start + 1) : max(nmax, index - vc.top());
			}

		}
	}
	return nmax;
}
};