class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        map<char, int> m1, m2;
        for (int i = 0; i < s.size(); i++)
            m1[s[i]]++;
        for (int j = 0; j < t.size(); j++)
            m2[t[j]]++;
        return m1 == m2;
    }
};