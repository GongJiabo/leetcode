#include <algorithm>    // std::reverse
#include <vector>

using std::vector; using std::reverse; using std::swap;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
      //reverse先对每行翻转
      reverse(matrix.begin(), matrix.end());
      //转置
      for (decltype(matrix.size()) i=0; i<matrix.size(); ++i)
        for (decltype(matrix.size()) j=i; j<matrix[i].size(); ++j)
          swap(matrix[i][j], matrix[j][i]);
    }
};