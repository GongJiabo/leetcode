```c++
class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> sum(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                sum[j][i] = sum[j - 1][i] + matrix[j - 1][i - 1];
            }
        }
        vector<int> ans(4);
        int res = INT_MIN;
        for (int i = 0; i <= n; ++i) {
            for (int len = 1; i + len <= n; ++len) {
                vector<int> v(m + 1);
                for (int j = 1; j <= m; ++j) {
                    v[j] = sum[i + len][j] - sum[i][j];
                }
                int first = 0;
                int last = 0;
                vector<int> f(m + 1);
                for (int k = 1; k <= m; ++k) {
                    if (f[k - 1] > 0) {
                        f[k] = f[k - 1] + v[k];
                        last = k;
                    } else {
                        f[k] = v[k];
                        first = last = k;
                    }
                    if (f[k] > res) {
                        res = f[k];
                        ans = {i, first - 1, i + len - 1, last - 1};
                    }
                }
            }
            
        }
        return ans;
    }
};
```

