// 贪心法

struct Interval
{
	int start;
	int end;

	Interval()
	{
		start = 0;
		end = 0;
	}
	Interval(int s, int e) : start(s), end(e){}
};

bool compare(const Interval& a, const Interval& b)
{
	if (a.end != b.end)
		return a.end < b.end;
	return a.start < b.start; 
}

class Solution 
{
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) 
	{
		if (intervals.size() == 0)
			return 0;
		//
		vector<Interval> itv;
		for (int i = 0; i < intervals.size(); ++i)
		{
			Interval tmp(intervals[i][0], intervals[i][1]);
			itv.push_back(tmp);
		}
		sort(itv.begin(), itv.end(), compare);
		//
		int res = 1;
		int pre = 0;
		for (int i = 1; i < itv.size(); i++)
		{
			if (itv[i].start >= itv[pre].end)
			{
				++res;
				pre = i;
			}
		}
		//
		return itv.size() - res;
	}
};