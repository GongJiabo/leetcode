
class Solution
{
private:
	vector<string> res;
	int dotnum;

public:
	vector<string> restoreIpAddresses(string s)
	{
		dotnum = 0;
		res.clear();
		if (s.size() == 0) return res;
		//
		findIpAddresses(s, 0, 0, "");
		return res;
	}
	void findIpAddresses(string& s,int index, int n,string ip)
	{
		if (n == 4 && index == s.size())
		{
			//剔除最后的一个'.'
			ip.pop_back();
			res.push_back(ip);
			return;
		}
		else
		{
			for (int i = index; i < s.size(); i++)
			{
				//最长取后面三位数字作为ip地址
				if (i - index < 3)
				{
					string sub = s.substr(index, i - index + 1);
					if (checkIpNumber(sub))
					{
						// 剩余的字符串必须能够组成 IP，不能太长也不能太短
						// 即剩下的ip元素为4-n，每个元素长度在1-3个数字
						// 剪枝！！！！
                        if(s.size()-i<=(4-n)*3 && s.size()-i>=(4-n))
						    findIpAddresses(s, i + 1, n + 1, ip + sub + '.');
					}
				}
			 }
		}
		return;
	}
	bool checkIpNumber(string s)
	{
		if (s.empty()) return false;
		if (s.size() >= 2 && s[0] == '0') return false;
		//
		int ip = atoi(s.c_str());
		if (ip >= 0 && ip <= 255) return true;
		return false;
	}
};