//1. 逐次比较
class Solution {
public:
bool isMatch(string s, string p)
{
	int n1 = s.size();
	int n2 = p.size();
	//双指针
	int p1 = 0, p2 = 0;
	//记录匹配到通配符的位置
	int marks = -1, markp = -1;
	while (p1 < n1)
	{
		if (p2 != n2 && (s[p1] == p[p2] || p[p2] == '?'))
		{
			//直接匹配
			p1++;
			p2++;
		}
		else if (p2!=n2 && p[p2] == '*')
		{
			//有通配符时，记录当前的p1、p2，并将p2前移动
			marks = p1;
			markp = p2;
			p2++;
		}
		else if (markp != -1)
		{
			//p2移动一步后和p1不匹配，则需要用'*'匹配掉当前p1,所有p1走一步，p2退一步，再继续比较
			p1 = marks + 1;
			p2 = markp + 1;
			marks++;
		}
		else return false;
	}
	while (p2 < n2)
	{
		//s已经匹配完全，但是p2指针还没有走完
		if (p[p2] == '*') p2++;
		else return false;
	}
	return true;
}
};


//2. 动态规划
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') dp[0][i] = dp[0][i - 1];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};