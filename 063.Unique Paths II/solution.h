#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
using std::vector; using std::prev;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        vector<int> vec(obstacleGrid.front().cbegin(), obstacleGrid.front().cend());
        //初始化第一行,将出现障碍"1"之前的位置初始为1,该位置及其后初始化为0
        auto flag = std::find(vec.begin(), vec.end(), 1);
        std::fill(vec.begin(), flag, 1);
        std::fill(flag, vec.end(), 0);
        //从第二行开始动态规划计算
        for (auto line = std::next(obstacleGrid.cbegin()); line != obstacleGrid.cend(); ++line) {
            auto iter = vec.begin();
            for (auto i : *line) {
                if (i) *iter = 0;
                else if (iter != vec.begin()) *iter += *prev(iter);
                ++iter;
            }
        }   
        return vec.back();
    }
};