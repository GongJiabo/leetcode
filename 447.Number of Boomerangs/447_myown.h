class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res=0;
        for(int i=0;i<points.size();i++)
        {
            unordered_map<int,int> record;
            for(int j=0;j<points.size();j++)
                if(i!=j)
                    record[dis(points[i],points[j])]++;
            for(unordered_map<int,int>::iterator iter=record.begin();
                iter!=record.end();iter++)
                if(iter->second >= 2)
                    res+=(iter->second)*(iter->second-1);
        }
        return res;
    }
    //
    int dis(const vector<int> &p1, const vector<int> &p2)
    {
        return (p1[0]-p2[0])*(p1[0]-p2[0])+((p1[1]-p2[1]))*(p1[1]-p2[1]);
    }
};