// 1.暴力解法依次遍历，从最大开始（超出时间限制）
class Solution {
public:
   	string minWindow(string s, string t)
	{
		int n1 = s.size();
		int n2 = t.size();
		int lmin = n1;
		int i, j;
		bool inside;
		string res = "";
		if (n2 > n1) return res;
		for (i = 0; i < n1; i++)
		{
			inside = true;
			for (j = n1 - 1; j >= i; j--)
			{
				int len = j - i + 1;
				string stmp;
				stmp = s.substr(i, len);
				string sstmp = stmp;
				for (int k = 0; k < n2; k++)
				{
					if (sstmp.find(t[k]) == string::npos)
					{

						inside = false;
						break;
					}
					else
					{
						int pos = sstmp.find(t[k]);
						sstmp.erase(pos, 1);
					}
				}
				if (inside)
				{
					if (lmin < len)
						continue;
					else
					{
						lmin = len;
						res = stmp;
					}
				}
			}
		}
		return res;
	}
};

//2.滑动窗口 
class Solution {
public:
	string minWindow(string s, string t)
	{
		//记录最短子串的开始位置和长度
		int start = 0, minLen = INT_MAX;
		int left = 0, right = 0;
		string res = s;
		//计数器
		unordered_map<char, int> window, needs;
		for (char c : t) needs[c]++;
		//在window中记录已经有多少字符符合要求
		int match = 0;
		while (right < s.size())
		{
			char c1 = s[right];
			if (needs.count(c1))
			{
				//加入window
				window[c1]++;
				//字符个数符号要求
				if (window[c1] == needs[c1])
					match++;
			}
			right++;
			while (match == needs.size())
			{
				// 更新最小子串的位置和长度
				if (right - left < minLen)
				{
					start = left;
					minLen = right - left;
				}
				char c2 = s[left];
				if (needs.count(c2))
				{
					window[c2]--;
					if (window[c2] < needs[c2])
						match--;
				}
				left++;
			}
		}
		return minLen == INT_MAX ?
			"" : s.substr(start, minLen);
	}
};