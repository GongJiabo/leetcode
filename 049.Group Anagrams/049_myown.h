class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		vector<string> ss = strs;
		int n = strs.size();
		//initialize
		int *selected = new int[n];
		for (int i = 0; i < n; i++)selected[i] = 0;
		//
		for (int j = 0; j < n; j++)
		{
			paixu(ss[j]);
		}
		//
		int nums = 0;
		for (int k = 0; k < n; k++)
		{
			if (k == 0)
			{
				nums++;
				selected[k] = 1;
			}
			else if (selected[k] == 0)
			{
				string s = ss[k];
				for (int r = 0; r < k; r++)
				{
					if (s == ss[r])
					{
						selected[k] = selected[r];
						break;
					}
				}
				if (selected[k] == 0)
				{
					nums++;
					selected[k] = nums;
				}
			}
			else if (selected[k] != 0) continue;
			
		}
		//for (int i = 0; i < n; i++) cout << selected[i] << endl;
		//push_back
		for (int i = 1; i <= nums; i++)
		{	
			vector<string> res1;
			for (int j = 0; j < n; j++)
			{
				if (selected[j] == i) res1.push_back(strs[j]);
			}
			res.push_back(res1);
		}
		delete []selected;
		return res;
    }
	void paixu(string &s)
	{
		int n = s.size();
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				if (s[i] > s[j]) chswap(s[i], s[j]);
			}
		}
	}
	void chswap(char &a, char&b)
	{
		char tmp = a;
		a = b;
		b = tmp;
	}
};