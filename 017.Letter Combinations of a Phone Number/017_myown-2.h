//回溯法

class Solution
{
private:
	const string lettermap[10] =
	{
		" ",
		"",
		"abc",
		"def",
		"ghi",
		"jkl",
		"mno",
		"pqrs",
		"tuv",
		"wxyz"
	};
	vector<string> res;

public:
	void findCombinations(const string& digits, int index, const string& s)
	{
		if (index == digits.size())
		{
			res.push_back(s);
			return;
		}
		else
		{
			int number = digits[index] - '0';
			string thisletter = lettermap[number];
			for (int i = 0; i < thisletter.size(); i++)
				findCombinations(digits, index + 1, s + thisletter[i]);
		}
		return;
	}

	vector<string> letterCombinations(string digits)
	{
        res.clear();
        if(digits.size()==0) return res; 
		findCombinations(digits, 0, "");
		return res;
	}
};