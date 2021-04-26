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
        // ɨ��freq��ά����ǰ����Ƶ����ߵ�k��Ԫ�أ�ά����С�ѣ�
        // �����ȶ����У�����Ƶ�������������ݶ��ǣ�Ƶ�ʣ�Ԫ�أ�����ʽ
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