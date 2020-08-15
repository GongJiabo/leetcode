//1. from leetcode
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> count;
        for(char c:s)
        {
            count[c]++;//key-value,计每个字母出现的个数
        }
        vector<pair<char,int>> vec;
        for(auto m:count)
        {
            vec.push_back(m);//放数组里，pair比较方便
        }
        sort(vec.begin(),vec.end(),[](pair<char,int> p1,pair<char,int> p2){return p1.second>p2.second;});
        string ans;
        for(auto v:vec)
        {
            ans=ans+string(v.second,v.first);
        }
        return ans;

    }
};

//2. lambda表达式
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> ump;
        for (const auto &c : s) {
            ++ump[c];
        }
        sort(s.begin(), s.end(), [&](char &a, char &b) { return ump[a] > ump[b] || (ump[a] == ump[b] && a < b); });
        return s;
    }
};
 
 