//1.利用map键值对保存字母次数信息(超出时间限制)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        int l = 0, r = l + m - 1; //在滑动区间[l,r]内搜索
        vector<int> res;
        //初始化pmap，利用键值对保存字母出现的次数
        map<char, int> pmap;
        for (int i = 0; i < m; i++)
            pmap[p[i]]++;
        //
        map<char, int> smap;
        //
        for (; r < n; l++, r++)
        {
            smap.clear();
            for (int i = l; i <= r; i++)
                smap[s[i]]++;
            if (smap == pmap)
                res.push_back(l);
        }
        return res;
    }
};

//2.直接利用数组存储
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(),l = p.size();
        vector<int> key(26, 0),freq(26, 0),res;
        for (char c : p) 
            key[c - 'a']++;
        for(int i = 0; i < n; i++){
            if(i >= l) 
                freq[s[i-l] - 'a']--;
            freq[s[i] - 'a']++;
            if(freq == key) 
                res.push_back(i + 1 - l);
        }
        return res;
    }
};
