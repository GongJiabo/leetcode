class Solution {
public:
string countAndSay(int n)
{
	if (n == 1) return string("1");
	//
	string *str = new string[n];
	str[0] = "1";
	for (int i = 1; i < n; i++)
	{
		string next;
		int size = str[i - 1].size();
		for (int j = 0; j < size; j++)
		{
			int count = 1;
			char c = str[i-1][j];
			for (int k = j + 1; k < size; k++)
			{
				if (str[i - 1][j] == str[i - 1][k])
				{
					count++;
					j++;
				}
				else
				{
					j = k-1;
					break;
				}
			}
			char cc = count + '0';
			next.push_back(cc);
			next.push_back(c);
		
		}
        str[i] = next;
	//	cout << str[i] << endl;
	}
	string result = str[n - 1];
	delete[]str;
	return result;
}
};