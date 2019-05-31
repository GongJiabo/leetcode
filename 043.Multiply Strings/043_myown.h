class Solution {
public:
string multiply(string num1, string num2) 
{
	int n1 = num1.size();
	int n2 = num2.size();
	int p = 0;
	vector<int> ret(n1 + n2, 0);	
	for (int i = n2 - 1; i >= 0; i--)
	{
		p = n2 - 1 - i;  // ret[p] 代表进位的数想
		for (int j = n1 - 1; j >= 0; j--)
		{
			//进位
			int res = (num2[i] - '0')*(num1[j] - '0') + ret[p];
			if (res >= 10) ret[p + 1] += res / 10;
			ret[p] = res % 10;
			p++;
		}
	}
	string ans = "";
	int terminal = n1 + n2 - 1;
	while (terminal >= 0 && ret[terminal] == 0)
		terminal--;
	for (int i = 0; i <= terminal; ++i) {
		ans = char(ret[i] + '0') + ans;
	}
	return ans == "" ? "0" : ans;
}
};