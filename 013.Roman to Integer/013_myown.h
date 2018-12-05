class Solution {
public:
int romanCharToInt(char ch){
	int d = 0;
	switch (ch){
	case 'I':
		d = 1;
		break;
	case 'V':
		d = 5;
		break;
	case 'X':
		d = 10;
		break;
	case 'L':
		d = 50;
		break;
	case 'C':
		d = 100;
		break;
	case 'D':
		d = 500;
		break;
	case 'M':
		d = 1000;
		break;
	}
	return d;
}

int romanToInt(string s) 
{
	int num = romanCharToInt(s[0]);
	for (int i = 1; i < s.size();i++)
	{
		int curr = romanCharToInt(s[i]);
		int prev = romanCharToInt(s[i - 1]);
		if (prev < curr)
		{
			num += curr - prev - prev;
		}
		else num += curr;
	}

	return num;
}
};