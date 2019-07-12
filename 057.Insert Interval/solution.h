// 1.pezy
#include <vector>
using std::vector;
#include <algorithm>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
     {
        auto low = std::lower_bound(intervals.cbegin(), intervals.cend(), newInterval, [](const Interval& lhs, const Interval& rhs){
            return lhs.start < rhs.start;
        });
        if (low != intervals.cbegin() && std::prev(low)->end >= newInterval.start) { --low; newInterval.start = low->start; }
        auto up = std::lower_bound(intervals.cbegin(), intervals.cend(), newInterval, [](const Interval& lhs, const Interval& rhs){
            return lhs.end < rhs.end;
        });
        if (up != intervals.cend() && up->start <= newInterval.end) { newInterval.end = up->end; ++up; }
        auto insert_pos = intervals.erase(low, up);
        intervals.insert(insert_pos, newInterval);
        return intervals;
    }
};

// 2.
class Solution {
	static bool comp(const vector<int> &a, const vector<int> &b){
		return a[1]<b[0];
	}
public:
	vector<vector<int> > insert(vector<vector<int> > &A, vector<int> &a) {
		int i=lower_bound(A.begin(),A.end(),a,comp)-A.begin(), j=0;
		for(j=i; j<A.size() && a[1]>=A[j][0]; ++j)
			a={min(a[0],A[j][0]), max(a[1],A[j][1])};
		A.insert(A.begin()+j,a);
		A.erase(A.begin()+i, A.begin()+j);
		return A;
	}
};