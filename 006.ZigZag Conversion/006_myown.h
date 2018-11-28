class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        int m = numRows;
        if (m <= 1) {
            return s;
        }
        int i, j;
        string res = "";
        //第一行
        for (j = 0; j < n; j += 2 * m - 2) {
            res.push_back(s[j]);
        }
		//中间行
        for (i = 1; i < m - 1; ++i) {
            for (j = 0; j < n; j += 2 * m - 2) {
                if (j + i < n) {
                    res.push_back(s[j + i]);
                }
                if (j + 2 * m - 2 - i < n) {
                    res.push_back(s[j + 2 * m - 2 - i]);
                }
            }
        }
		//最后一行
        for (j = m - 1; j < n; j += 2 * m - 2) {
            res.push_back(s[j]);
        }
        return res;
    }
};
