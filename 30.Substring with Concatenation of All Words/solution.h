class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        int n = words.size(), m = words[0].size();
        unordered_map<string, int> m1;
        for (auto &a : words) ++m1[a];                       //创建键值对，key为各单词，value为默认1（0+1）？
        for (int i = 0; i <= (int)s.size() - n * m; ++i) {
            unordered_map<string, int> m2;
            int j = 0; 
            for (j = 0; j < n; ++j) {
                string t = s.substr(i + j * m, m);
                if (m1.find(t) == m1.end()) break;
                ++m2[t];										
                if (m2[t] > m1[t]) break;					  //两个连续的同样单词不满足条件，判断次数
            }
            if (j == n) res.push_back(i);					  //所有单词匹配完，j==n
        }
        return res;
    }
};