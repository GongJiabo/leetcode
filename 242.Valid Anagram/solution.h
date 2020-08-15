//1.
class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash1[128];
        int hash2[128];
        memset(hash1, 0, sizeof(int) * 128);
        memset(hash2, 0, sizeof(int) * 128);
        for (char c : s) {
            hash1[c - '0'] ++;
        }
        for (char c : t) {
            hash2[c - '0'] ++;
        }
        for (int i = 0; i < 128; i ++) {
            if (hash1[i] != hash2[i]) {
                return false;
            }
        }
        return true;
    }
};

//2.
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;//若不等直接返回
        int wd[26] = {};
        for (int i = 0; i < s.size(); i++) 
            wd[s[i] - 'a']++;
        for (int i = 0; i < t.size(); i++) 
            if (--wd[t[i] - 'a'] < 0) return false;//若待判断的值减去t的某个字符后小于0则直接返回，把最好情况的复杂度常数项量级降低
        return true;
    }
};
