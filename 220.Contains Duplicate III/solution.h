//1. leetcode
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> set;
        for(int i = 0; i < nums.size(); i ++) {
            auto it = set.lower_bound((long) nums[i] - t);
            if(it != set.end() && *it <= (long) nums[i] + t) return true;
            set.insert(nums[i]);
            if(set.size() == k + 1) set.erase(nums[i - k]); //保证滑动窗口
        }
        return false;
    }
};

//2. map
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k < 1 || t < 0 || nums.empty()) return false;
        int N = nums.size();
        map<long, int> m{{nums[0], 1}};
        for (int i = 1; i < N; ++i) {
            auto it = m.lower_bound(nums[i]);
            if (it != m.end() && abs(it->first - (long)nums[i]) <= t) return true;
            if (it != m.begin() && abs((--it)->first - (long)nums[i]) <= t)  return true;
            ++m[nums[i]];
            if (i - k >= 0 && --m[nums[i - k]] == 0) m.erase(nums[i - k]);
        }
        return false;
    }
};
