// 1. 递归，时间超限
class Solution {
public:
    int max3(int a,int b,int c)
    {
        return max(max(a,b),c);
    }

    int divideInteger(int n)
    {
        if(n==1)
            return 1;
        //
        int res=-1;
        for(int i=1;i<=n-1;++i)
            res = max3(res, i*(n-i), i*divideInteger(n-i));
        return res;
    }
    
    int integerBreak(int n) {
        assert(n>=2);
        return divideInteger(n);
    }
};

// 2. 使用辅助数组存储
class Solution {
private:
    vector<int> memo;
public:
    int max3(int a,int b,int c)
    {
        return max(max(a,b),c);
    }

    int divideInteger(int n)
    {
        if(n==1)
            return 1;
        //
        if(memo[n] != -1)
            return memo[n];
        //
        int res=-1;
        for(int i=1;i<=n-1;++i)
            res = max3(res, i*(n-i), i*divideInteger(n-i));
        memo[n] = res;
        return res;
    }
    
    int integerBreak(int n) {
        assert(n>=2);
        memo=vector<int>(n+1,-1);
        return divideInteger(n);
    }
};

// 3. 动态规划
// for(int i=1; i<=n-1; ++i)
//     dp[i] = max(dp[i], i*(n-i), i*dp[i-1])
class Solution {
public:
    int max3(int a,int b,int c)
    {
        return max(max(a,b),c);
    }
    
    int integerBreak(int n) {
        assert(n>=2);
        vector<int> dp(n+1,-1);
        dp[1]=1;
        for(int i=2;i<=n;++i)
        {
            // 尝试将i分割成 j 与 i-j 两部分
            for(int j=1;j<=i-1;++j)
                dp[i] = max3(dp[i], j*(i-j), j*dp[i-j]);
        }

        return dp[n];
    }
};

