//1.
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
             if (! isornot(s[i])) {i ++; continue;} 
             if (! isornot(s[j])) {j --; continue;} 
             swap (s[i++],s[j--]);
        } 
        return s;
    }
    bool isornot(char c) {
        return (c == 'a' || c == 'A' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'e' || c == 'E') ;
    }
};
