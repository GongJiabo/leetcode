class Solution
{
private:
	vector<vector<string>> res;
public:
	vector<vector<string>> partition(string s)
	{
		res.clear();
		if (s.size() == 0) return res;
		findCombination(s, 0, {});
		return res;
	}

	void findCombination(string s,int start, vector<string> temp)
	{
		if (start == s.size())
		{
			res.push_back(temp);
			return;
		}
		else
		{

			for (int i = start; i<s.size(); i++)
			{
				string sub = s.substr(start, i - start + 1);
				if (isPalindrome(sub))
					temp.push_back(sub);
				else continue;
				findCombination(s, i+1, temp);
				temp.pop_back();
			}
		}
	}


	bool isPalindrome(string s)
	{
		int n = s.size();
		for (int i = 0, j = n - 1; i < j; i++, j--)
			if (s[i] != s[j])
				return false;
		return true;
	}
};