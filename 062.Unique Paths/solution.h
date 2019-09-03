class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n) std::swap(m, n);
        if (m < 2) return m;
        std::vector<int> steps(n, 1);
        for (int i=1; i<m; ++i)
            for (int j=1; j<n; ++j)  
                steps[j] += steps[j-1];
        return steps[n-1];
    }
};

//由于我们只需要知道到 End 的步数，所以我们仅需要存储 End 这一行与其上一行的步数即可。而恰巧，我们是斜边相加。所以我们只需要将最后一行的前一格（真实的最后一行值）与自身（还处于倒数第二行的值）相加即可。故一个数组搞定。