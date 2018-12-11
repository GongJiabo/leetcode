#include <string> 
#include <vector>
using std::string; using std::vector;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";
        for (size_t i=0; i<strs.front().size(); ++i) {                     //strs.front() 即 strs[0]
            for (const auto &str : strs)								   //自动类型变量，基于范围的for循环
                if (i == str.size() || str.at(i) != strs.front().at(i))    //判断字符串长度并判断是否相等	
                    return strs.front().substr(0, i); 	
        }
        return strs.front();
    }
};