// 1.递归回溯法(时间超限)
// 我的写法似乎遍历所有可能的子集，没有剪支因此时间超限
class Solution {
public:
    // 最多m个0, n个1
    void dfs(vector<string>& strs, int m, int n, int index, vector<string> res, int& maxsize)
    {
        if (m < 0 || n < 0)
            return;
        maxsize = max(maxsize, int(res.size()));
        for (int i = index; i < strs.size(); ++i)
        {
            string str = strs[i];
            int m0 = count(str.begin(), str.end(), '0');
            int n0 = count(str.begin(), str.end(), '1');
            res.push_back(str);
            dfs(strs, m - m0, n - n0, i+1, res, maxsize);
            res.pop_back();
        }
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int vn = strs.size();
        if (vn < 1)
            return 0;
        //
        vector<string> res;
        int maxsize = 0;
        dfs(strs, m, n, 0, res, maxsize);
        return maxsize;

    }
};

// 2.动态规划(二维，两个容量的背包问题)
class Solution {
public:
    // 动态规划
    // m - 0     n - 1
    int findMaxForm(vector<string>& strs, int m, int n) {
        int vn = strs.size();
        if (vn < 1)
            return 0;
        //
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        //
        for (string& str:strs)
        {
            int m0 = count(str.begin(), str.end(), '0');
            int n1 = count(str.begin(), str.end(), '1');
            //
            for (int i0 = m; i0 >= m0; --i0)
            {
                for (int j1 = n; j1 >= n1; --j1)
                {
                    // 状态转移！！！！
                    dp[i0][j1] = max(dp[i0][j1], dp[i0 - m0][j1 - n1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};