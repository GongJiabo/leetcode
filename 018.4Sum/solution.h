#include <vector>
using std::vector;
#include <algorithm>
#include <unordered_map>
#include <set>

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        if (num.size() < 4) return vector<vector<int>>{};
        std::set<vector<int>> ret;
        std::sort(num.begin(), num.end());
        std::unordered_map<int, vector<std::pair<int, int>>> cache;   //pair为组合两个数据的结构体  key：两数和  vector(value:pair(序号1，序号2))
        //保存从i开始到后面所有数字的两两之和，和(key)相同的保存在vector<std::pair>内
        for (size_t i=0; i<num.size(); ++i)
            for (size_t j=i+1; j<num.size(); ++j)
                cache[num[i]+num[j]].emplace_back(i, j);     		  //构造并插入一个键值对(保存两个数的和)
        
        for (const auto &rp : cache) {
            auto found = cache.find(target - rp.first);				  //查找另外两个数的和等于target减去当前的两数和
            if (found != cache.end())
                for (const auto &low : rp.second)					  //low为pair类型
                    for (const auto &high : found->second)			  //found为找到的符号要求的两数和的unorder_map类型
                        if (low.second < high.first) ret.insert(vector<int>{num[low.first], num[low.second], num[high.first], num[high.second]});
        }
		//判断凉凉
        
        return vector<vector<int>>(ret.cbegin(), ret.cend());
    }
};