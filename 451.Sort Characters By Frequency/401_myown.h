class Solution {
public:
    static bool cmp(pair<char, int>& a, pair<char, int>& b)
    {
        return a.second > b.second;
    }

    string frequencySort(string s) 
    {
        string res = "";
        map<char,int> record;
        //
        int n = s.size();
        for (int i = 0; i < n; i++)
            record[s[i]]++;
        //
        vector<pair<char, int>> vpr;
        for (auto it = record.begin(); it != record.end(); it++)
            vpr.push_back(make_pair(it->first, it->second));
        sort(vpr.begin(), vpr.end(), cmp);
        //
        for (int i = 0; i < vpr.size(); i++)
        {
            for (int j = 0; j < vpr[i].second; j++)
                res += vpr[i].first;
        }
        return res;
    }
};