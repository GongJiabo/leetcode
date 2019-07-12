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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
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

//haoel
truct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

//Two factos sorting [start:end]
bool compare(const Interval& lhs, const Interval& rhs){
    return (lhs.start==rhs.start) ? lhs.end < rhs.end : lhs.start < rhs.start;
}

vector<Interval> merge(vector<Interval> &intervals) {

    vector<Interval> result;

    if (intervals.size() <= 0) return result;
    //sort the inervals. Note: using the customized comparing function.
    sort(intervals.begin(), intervals.end(), compare);
    for(int i=0; i<intervals.size(); i++) { 
        int size = result.size();
        // if the current intervals[i] is overlapped with previous interval.
        // merge them together
        if( size>0 && result[size-1].end >= intervals[i].start) {
            result[size-1].end = max(result[size-1].end, intervals[i].end); 
        }else{
            result.push_back(intervals[i]);
        }
    }
    
    return result;
}

