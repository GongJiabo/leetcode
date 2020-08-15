//题首先是字符串的分离。 根据空格进行分离 C++没有直接split函数很蛋疼
//分离后就是两个哈希表 双向映射 和leetcode[205]题一样。
//要注意的地方是： 分离字符串时最后一个字符串 没有空格判定 直接末尾判定即可。
//1. leetcode
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char,string> mp;
        map<string,char> pm;
        int j=0;
        vector<string>arr;
        for(int i=0;i<str.size();++i){
            if(i==str.size()-1){
                arr.push_back(str.substr(j,str.size()-j));
            }
            if(str[i]==' '){
                arr.push_back(str.substr(j,i-j));
                j=i+1;
            }
        }
        if(pattern.size()!=arr.size()) return false;
        for(int i=0;i<pattern.size();++i){
            if(mp.find(pattern[i])!=mp.end() && mp[pattern[i]]!=arr[i]){
                return false;
            }
            if(pm.find(arr[i])!=pm.end()&& pm[arr[i]]!=pattern[i])
                return false;
            
            mp[pattern[i]]=arr[i];
            pm[arr[i]]=pattern[i];
        }
        return true;

    }
};
 
 class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> map;
        unordered_map<string, char> rmap;
        stringstream ss(str); string s;
        for(char c : pattern) {
            if(!(ss >> s) || (map.count(c) == 1 && map[c] != s) || (rmap.count(s) == 1 && rmap[s] != c)) return false;
            map[c] = s; rmap[s] = c;
        }
        return (ss >> s) ? false : true;
    }
};

 //2. haoel
 class Solution {

private::
	//利用stringstream分割字符串！
    vector<string> split(string str, char delimiter) {
        vector<string> internal;
        stringstream ss(str); // Turn the string into a stream.
        string tok;
        
        while(getline(ss, tok, delimiter)) {
            internal.push_back(tok);
        }
        
        return internal;
    }

public:
    //用两个unordered_map相互映射！
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> dict_pattern;
        unordered_map<string, char> dict_string;
        
        int len = pattern.size();
        vector<string> strs = split(str, ' ');
        
        if (len != strs.size()) return false;
        
        for(int i=0; i<len; i++) {
            char& ch = pattern[i];
            string& s = strs[i];
            
            if ( dict_pattern.find(ch) == dict_pattern.end() ) {
                dict_pattern[ch] = s;
            }
            
            if ( dict_string.find(s) == dict_string.end() ) {
                dict_string[s] = ch;
            }
            
            if ( dict_pattern[ch] != s || dict_string[s] != ch ) {
                return false;
            }
            
        }
        return true;
    }
};

 