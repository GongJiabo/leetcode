// 1.leetcode
class Solution {
public:
    int lengthOfLastWord(string s)
    {
        string word;
        stringstream ss(s);//字符串输入输出流自动过滤空格
        while(ss>>word){}//读取到最后一个单词
        return word.size();
    }
};

// 2. leetcode
class Solution {
public:
   int lengthOfLastWord(string s){
        int length  = 0;      // 当前单词长度
        bool isWord = false;  // 是否遇到了单词

        for(int i = s.length() - 1; i >= 0; i--){
            if( s[i] != ' ' ){
                isWord = true;
                length++;
            }else if( s[i] == ' '  && isWord ){
                return length;
            }
        }
        return length;
    }

};

// 3.pezy(in C)
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len{0};
        for (int beg = 0; *s; ++s)
            if (*s == ' ') beg = 0;
            else len = ++beg;
        return len;
    }
};

// 4.pezy(in STL)
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        string str(s);
        //删除最后一个字母后面所有的内容，保证结尾不是空格
        str.erase(str.find_last_not_of(' ')+1);
        if (str.empty()) return 0;
        auto found = str.find_last_of(' ');
        if (found == string::npos) return str.size();
        else return str.size() - found - 1;
    }
};