//1. 提交不通过，判断三点是否共线时，会出现大数成大数的情况。
//后来发现输入数组中会出现重复的点，需要考虑去重。
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        if (n < 3) return n;
        vector<int> count;
        //
        for (int i = 0; i < n; i++)
        {
         
            for (int j = i+1; j < n; j++)
            {  
                int temp = 0;
                if (points[i] == points[j])
                    continue;
                //
                for (int k = 0; k < n; k++)
                {
                    if (isline(points[i], points[j], points[k]))
                        temp++;
                }
                count.push_back(temp);
            }
        }
        if(count.size()==0)
            return points.size();
        else
            return *max_element(count.begin(), count.end());

    }
    bool isline(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3)
    {
        long x1, y1, x2, y2, x3, y3;
        x1 = p1[0];
        y1 = p1[1];
        x2 = p2[0];
        y2 = p2[1];
        x3 = p3[0];
        y3 = p3[1];
        return (y3 - y1) * (x3 - x2) == (y3 - y2) * (x3 - x1);
    }
};