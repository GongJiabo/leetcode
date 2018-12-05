#include <algorithm>
#include <vector>

using std::vector; using std::prev; using std::max; using std::min;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int ret{0};
        for (auto beg = height.begin(), end = prev(height.end()); beg < end; *beg < *end ? ++beg : --end)   //perv()--前一个位置，用迭代器！！
            ret = max(ret, static_cast<int>(end - beg)*min(*beg, *end));
        return ret;
    }
};