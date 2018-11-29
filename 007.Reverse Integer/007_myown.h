class Solution {
public:
    int reverse(int x) {
    	string str = to_string(abs(x));
	    int n = str.size();
    	double result = 0;
    	for (int i = 0; i < n; i++)
    	{
	    	double temp = 0;
	    	temp = atoi(str.substr(n - i - 1, 1).c_str())* pow(10, n-i-1);
            if(temp < 0) return 0;
	    	result += temp;
    	}
        if(result > pow(2,31) - 1 || result < -pow(2,31)) return 0;
        else if(x<0) return -result;
	    else return result;
    }
};