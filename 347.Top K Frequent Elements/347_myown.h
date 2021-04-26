class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n || k<0) return {};
        //
        unordered_map<int,int> freq;
        for(auto x:nums)
            ++freq[x];
        //
        assert(k<= freq.size());
        // 扫描freq，维护当前出现频率最高的k个元素（维护最小堆）
        // 在优先队列中，按照频率排序，所以数据对是（频率，元素）的形式
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        for(unordered_map<int,int>::iterator it = freq.begin(); it!=freq.end(); ++it)
        {
            if(pq.size()==k)
            {
                if( it->second > pq.top().first )
                {
                    pq.pop();
                    pq.push(make_pair(it->second, it->first));
                }
            }
            else
                pq.push(make_pair(it->second, it->first));
        }
        //
        vector<int> res;
        while(!pq.empty())
        {
            res.push_back( pq.top().second );
            pq.pop();
        }
        return res;
    }
};