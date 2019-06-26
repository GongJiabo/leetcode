double pow(double x, int n) 
{
    return std::pow(x, n);
}

//1. 蛮力法，连乘，超出时间限制！！
class Solution 
{
public:
    double myPow(double x, int n) 
    {
        double res=1;
        for(int i=0;i<abs(n);i++)
            res*=x;
        if(n>0) return res;
        else if(n<0) return 1.0/res;
        else return 1.0;
    }
};

//2. 分奇数偶数，减半乘法，超出时间限制！！
class Solution 
{
public:
    double myPow(double x, int n) 
    {
        if(n>0)
        {
            if(n%2==0) 
                return myPow(x,n/2)* myPow(x, n/2);
            else if(n%2==1) 
                return x* myPow(x, n/2) * myPow(x, n/2);
        }
        else if(n<0)
        {
            return myPow(1/x,-n);
        }
        return 1.0;
    }
};
