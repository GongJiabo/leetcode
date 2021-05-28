class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        // 当天未操作
        int nopro = 0;
        // 第一次买入
        int buy1 = -prices[0];
        // 第一次卖出(已经买入第一次)
        int sell1 = 0;
        // 第二次买入
        int buy2 = -prices[0];
        // 第二次卖出
        int sell2 = 0;
        for(int i=1; i<n; ++i)
        {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2,buy2+prices[i]);
        }
        return max(sell1,sell2);
    }
};