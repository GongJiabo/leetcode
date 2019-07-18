class Solution {
public:
    string getPermutation(int n, int k) 
	{
		int nn = n;
		string str{};
		vector<int> vc,vn;
		for (int j = 1; j <= n; j++) vn.push_back(j);
		//
		while (n != 0)
		{
			int n1 = countnum(k, n);
			vc.push_back(n1);
		}
		for (int i = 0; i < nn; i++)
		{
			int number = vn[vc[i] - 1];
			str.push_back((number)+48);
			vn.erase(vn.begin() + vc[i] - 1);
		}
		return str;
    }
	//x为在该位置上的第几个，n为剩余位数
	int countnum(int &k,int &n)
	{
		int i;
		for (i = 1;i*func(n - 1) < k; i++) {}
		n--;
		k = k - (i - 1)*func(n);
		return i;
	}

	int func(int x)
	{
		register int i,f=1;  //定义寄存器变量  
		for(i=1;i<=x;i++)  
			f*=i;  
		return f;  
	}
};