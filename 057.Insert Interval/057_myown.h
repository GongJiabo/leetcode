class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
	{

		int n = intervals.size();
		if (n <= 1) return intervals;
		//
		vector<vector<int>> temp = intervals;
		vector<vector<int>> res(n);
		while (true)
		{
			//
			bool mfinal = false;
			res.clear();
			res.push_back(temp[0]);
			for (int i = 1; i < temp.size(); i++)
			{
				bool merge = false;
				for (int j = 0; j < res.size(); j++)
				{
					if (temp[i][0] <= res[j][0] && temp[i][1] <= res[j][1] && temp[i][1] >= res[j][0])
					{
						res[j][0] = temp[i][0];
						mfinal = true;
						merge = true;
					}
					else if (temp[i][0] >= res[j][0] && temp[i][1] <= res[j][1])
					{
						mfinal = true;
						merge = true;
					}
					else if (temp[i][0] <= res[j][0] && temp[i][1] >= res[j][1])
					{
						res[j][1] = temp[i][1];
						res[j][0] = temp[i][0];
						mfinal = true;
						merge = true;
					}
					else if (temp[i][0] >= res[j][0] && temp[i][1] >= res[j][1] && temp[i][0] <= res[j][1])
					{
						res[j][1] = temp[i][1];
						mfinal = true;
						merge = true;
					}
				}
				if (!merge) res.push_back(temp[i]);
			}
			if (!mfinal) break;
			temp = res;
		}
		//return temp;
		//去重，排序 
		set<vector<int>> set_res;
		for (int i = 0; i < temp.size(); i++)
			set_res.insert(temp[i]);
		vector<vector<int>> unique(set_res.begin(),set_res.end());
		return unique;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};