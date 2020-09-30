//1. from pezy
class Solution {
public:
    string simplifyPath(string path) {
        string ret, tmp;
        vector<string> stack;
        for ( istringstream iss(path); getline(iss, tmp, '/');  ) {
            if (tmp == ".." && !stack.empty()) stack.pop_back();
            else if (tmp == "." || tmp == ".." || tmp == "") continue;
            else stack.push_back(tmp);
        }
        for (auto str : stack) { ret += "/" + str; }
        return ret.empty() ? "/" : ret;
    }
};


//2. 利用stringstream和getline分割字符串
class Solution {
public:
    string simplifyPath(string path) {
        stringstream is(path);
        vector<string> strs;
        string res = "", tmp = "";
        while(getline(is, tmp, '/')) {
            if(tmp == "" || tmp == ".")
                continue;
            else if(tmp == ".." && !strs.empty())
                strs.pop_back();
            else if(tmp != "..")
                strs.push_back(tmp);
        }
        for(string str:strs) 
            res +=  "/" + str;
        if(res.empty())
            return "/";
        return res;
    }
};
