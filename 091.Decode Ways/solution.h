// 1.DP
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] != '0') {
                f[i] += f[i - 1];
            }
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) {
                f[i] += f[i - 2];
            }
        }
        return f[n];
    }
};

// 2. 空间优化的DP
// 注意到在状态转移方程中，f_i 的值仅与 f_i-1 和 f_i-2有关，因此我们可以使用三个变量进行状态转移，省去数组的空间。
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        // a = f[i-2], b = f[i-1], c = f[i]
        int a = 0, b = 1, c;
        for (int i = 1; i <= n; ++i) {
            c = 0;
            if (s[i - 1] != '0') {
                c += b;
            }
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) {
                c += a;
            }
            tie(a, b) = {b, c};
        }
        return c;
    }
};
