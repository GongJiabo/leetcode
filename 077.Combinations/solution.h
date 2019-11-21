#include <vector> 
#include <functional>

using std::vector; using std::function;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> retv;
        vector<int> vec(k);
        function<void(int, int, int)> combine = [&](int i, int n, int k) {
            for (int j=k-1; i>0; j ? combine(i, n, j) : retv.push_back(vec))
                vec[j] = i--;
        };
        combine(n,n,k);
        return retv;
    }
};

// 核心算法

void combine(int i, int n, int k)
{
    while (i<=n)
    {
        vec[vec.size() - k] = i++;
        if (k == 1) retv.push_back(vec);
        else combine(i, n, k-1);
    }
}