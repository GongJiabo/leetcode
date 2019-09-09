class Solution {
public:
	string addBinary(string a, string b)
	{
		string res("");
		int n1 = a.size(), n2 = b.size();
		//补齐
		while (n1 < n2)
		{
			a = '0' + a;
			n1++;
		}
		while (n2 < n1)
		{
			b = '0' + b;
			n2++;
		}

		//
		int carry = 0;
		auto it1 = a.rbegin(), it2 = b.rbegin();
		for (; it1 != a.rend(), it2 != b.rend(); it1++, it2++)
		{
			int a1 = *it1 - '0';
			int a2 = *it2 - '0';
			if (a1 + a2 + carry < 2)
			{
				res.insert(res.begin(), (a1 + a2 + carry) + '0');
				carry = 0;
			}
			else
			{
				res.insert(res.begin(), ((a1 + a2 + carry) - 2) + '0');
				carry = 1;
			}
		}
		if (carry == 1) res.insert(res.begin(), '1');
		return res;
	}
};