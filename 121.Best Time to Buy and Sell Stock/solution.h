// 单调栈
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        vector<int> St;
        prices.emplace_back(-1); \\ 哨兵👨‍✈️
        for (int i = 0; i < prices.size(); ++ i){
            while (!St.empty() && St.back() > prices[i]){ \\ 维护单调栈📈
                ans = std::max(ans, St.back() - St.front()); \\ 维护最大值
                St.pop_back();
            }
            St.emplace_back(prices[i]);
        }

        return ans;
    }
};
