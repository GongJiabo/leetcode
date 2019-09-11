class Solution {
public:
	int mySqrt(int x) 
	{
		long long n = 0;
		do
		{
			n++;
		} while (n*n <= x);
		return n-1;
	}
};