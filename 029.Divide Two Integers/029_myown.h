class Solution {
public:
int divide(int dividend, int divisor)
{
	if (dividend == 0) return 0;
	int res = 0;
	bool zf1 = dividend > 0 ? true : false;
	bool zf2 = divisor > 0 ? true : false;
	dividend = abs(dividend);
	divisor = abs(divisor);
	while (dividend > 0)
	{
		dividend -= divisor;
		res++;
	}
	if (dividend != 0) res--;
	if ((zf1&&zf2) || (!zf1 && !zf2))
	{
		if (res > INT_MAX) return INT_MAX;
		else return res;
	}
	else
	{
		if (-res < INT_MIN) return INT_MAX;
		else return -res;
	}
}
};