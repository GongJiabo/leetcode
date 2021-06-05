// 1.动态规划
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int** d = new int*[m+1];
        for (int i = 0; i < m+1; ++i)
        {
            d[i] = new int[n+1];
            memset(d[i], 0, sizeof(int)*(n+1));
        }

        int cnt[2];
        for (auto str : strs)
        {
            Get0And1(str, cnt);
            for (int i = m; i >= cnt[0]; --i)
            {
                for (int j = n; j >= cnt[1]; --j)
                {
                    d[i][j] = max(d[i][j], 1 + d[i-cnt[0]][j-cnt[1]]);
                }
            }
        }

        return d[m][n];
    }

    // 计算str里包含的0和1的个数，保存在cnt里
    void Get0And1(string& str, int* cnt)
    {
        memset(cnt, 0, sizeof(int)*2);
        int n = str.size();
        for (int i = 0; i < n; ++i)
        {
            ++cnt[str[i] - '0'];
        }
    }
};

// 回溯(自顶向下)
// 自顶向下
class Solution {
public:
    vector<vector<vector<int>>> status;
    int MaxStrNum(vector<string>& strs, int idx, int m, int n){
        if (status[idx][m][n] != -1){
            return status[idx][m][n];
        }
        int num0 = 0;
        int num1 = 0;
        for (auto& c : strs[idx]){
            if (c == '0'){
                num0++;
            }else if (c == '1'){
                num1++;
            }
        }
        if (idx == 0){
            return num0 <= m && num1 <=n;
        }
        int max;
        if (num0 > m || num1 > n){
            max = MaxStrNum(strs, idx -1, m, n);
        }else{
            // 和动态规划一个思路
            max = std::max(MaxStrNum(strs, idx -1, m, n), 
                MaxStrNum(strs, idx -1, m - num0, n - num1)+1);
        }
        status[idx][m][n] = max;
        return max;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        decltype(strs.size()) sz = strs.size();
        vector<int> ele(n+1, -1);
        status.resize(sz, vector<vector<int>>(m+1, ele));
        int max = MaxStrNum(strs, sz -1, m, n);
        return max;
    }
};
