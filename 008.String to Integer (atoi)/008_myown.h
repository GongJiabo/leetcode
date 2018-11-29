class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
	int length = 0;
	int start = 0;
	double result = 0;
	bool isFushu = false;
	//bool already_fuhao = false;
	int i;
	for (i = 0; i < n; i++)
	{
		if (str[i] == ' ') continue;
		else if (!isdigit(str[i]) && str[i] != '-' && str[i] != '+') return 0;
		else if (str[i] == '-')
		{
			if (isdigit(str[i+1]))
			{
				i++;
				start = i;
				isFushu = true;
				break;
				//already_fuhao = true;
				//continue;
			}
			else return 0;
		}
		else if (str[i] == '+')
		{
			if (isdigit(str[i + 1]))
			{
				i++;
				start = i;
				isFushu = false;
				break;
				//already_fuhao = true;
				//continue;
			}
			else return 0;
		}
		else if (isdigit(str[i]))
		{
			start = i;
			break;
		}
	}
	for (; i < n; i++)
	{
		if (isdigit(str[i]))
		{
			length++;
		}
		else break;
	}
	result = atof(str.substr(start, length).c_str());
	//
	if (isFushu) result = -result;
	if (result < INT_MIN) return INT_MIN;
	else if (result > INT_MAX) return INT_MAX;
	//
	return result;
    }
};