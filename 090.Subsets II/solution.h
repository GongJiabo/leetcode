#include <vector>
#include <algorithm>
using std::vector; 

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> ret{{}};
        for (size_t i=0, b=0, e=0; i<S.size(); ++i)
            for (b=(i && S[i] == S[i-1] ? e : 0), e=ret.size(); b<e; ++b)
                ret.insert(ret.end(), ret[b])->push_back(S[i]);
        return ret;
    }
};


//
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        __subsetsWithDup(nums, 0, tmp);
        return res;
    }
private:
    void __subsetsWithDup(vector<int>& nums, int start, vector<int> &tmp){
        res.push_back(tmp);
        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i - 1] == nums[i]) // (i != start && nums[i - 1] == nums[i]) 
                continue;
            tmp.push_back(nums[i]);
            __subsetsWithDup(nums, i + 1, tmp);
            tmp.pop_back();
        }
    }
};
