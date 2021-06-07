// 贪心法
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ng = g.size();
        int ns = s.size();
        //
        // 从大到小排序
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        //
        int res = 0;
        int j2 = 0;
        for(int i=0;i<ng;++i)
        {
            for(int j = j2;j<ns;++j)
            {
                if(g[i] <= s[j])
                {    
                    ++res;
                    j2 = ++j;
                    break;
                }
            }
        }
        //
        return res;
    }
};