class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        if (n != t.size())
            return false;
        //
        unordered_map<char, char> rec1, rec2;
        for (int i = 0; i < n; i++)
        {
            if (rec1.count(s.at(i)) && rec1[s.at(i)] != t.at(i))
                return false;
            if (rec2.count(t.at(i)) && rec2[t.at(i)] != s.at(i))
                return false;
            rec1[s.at(i)] = t.at(i);
            rec2[t.at(i)] = s.at(i);
        }
        return true;
    }
};