//
//  Solution.h
//  Test
//
//  Created by pezy on 12/27/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//

#ifndef Test_Solution_h
#define Test_Solution_h

#include <vector>
#include <string>
#include <array>

using std::vector; using std::string; using std::array;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret{""};
        array<string, 10> map{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};   
        for (auto digit : digits) {
            vector<string> tmp;
            for (auto c : map[digit - '0'])   // 将按键数字转为 map 的角标, 最简单的方式就是用 digit - '0'.
                for (const auto &pre : ret)   // 我们希望第一层迭代的字符称为后面的前缀，如"23"中，"abc"应分别称为"def"的前缀。
                    tmp.push_back(pre + c);
            ret = tmp;
        }
        return ret;
    }
};

#endif