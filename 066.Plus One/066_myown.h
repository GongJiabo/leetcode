// 1. wrong answer (int / lon long 数据类型范围不够)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
	{
		int n = digits.size();
		long long sum = 0, i = 0;
		vector<int> res;
		for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); it++)
		{
			sum += *it * pow(10, i);
			i++;
		}
		sum++;
		while (sum != 0)
		{
			int data = sum % 10;
			res.insert(res.begin(), data);
			sum = sum / 10;
		}
		return res;
    }
};

// 2. 单个处理数字
class Solution {
public:
	vector<int> plusOne(vector<int>& digits)
	{
		int n = digits.size();
		if (digits.back() != 9)
			digits.back()++;
		else
		{
			vector<int>::reverse_iterator it;
			for (it = digits.rbegin(); it != digits.rend();)
			{
				if (*it == 9)
				{
					*it = 0;
					it++;
				}
				else
				{
					(*it)++;
					break;
				}
			}
			if (it == digits.rend())
				digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};