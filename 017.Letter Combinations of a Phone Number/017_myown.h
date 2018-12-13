class Solution {
public:
string NumberToLetter(char c)
{
	switch (c)
	{
	case '1':
		return "";
	case '2':
		return "abc";
	case '3':
		return "def";
	case '4':
		return "ghi";
	case '5':
		return "jkl";
	case '6':
		return "mno";
	case '7':
		return "pqrs";
	case '8':
		return "tuv";
	case '9':
		return "wxyz";
	}
}

vector<string> diedai(vector<string> str, char c)
{
	//
	string sn = NumberToLetter(c);
	int n = sn.size();
	//
	vector<string> out;
	if (str.size() == 0)
	{
		for (int j = 0; j < n; j++)
		{
			string ss(1,sn[j]);
			out.push_back(ss);
		}
	}
	//
	for (int i = 0; i < str.size(); i++)
	{
		for (int j = 0; j < n; j++)
		{
			string ss = str[i] + sn[j];
			out.push_back(ss);
		}
	}
	return out;
}

vector<string> letterCombinations(string digits)
{
	vector<string> res{};
	int n = digits.length();
	if (n == 0) return vector<string>{};
	//
	for (int i = 0; i < n; i++)
	{
		res = diedai(res, digits[i]);
	}
	return res;
}
};