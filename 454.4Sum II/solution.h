//from leetcode
//二分法：
//求和法
//(1)A与B所有元素求和，得到数组first；
//   C与D所有元素求和，得到数组second：
//2）对second进行排序；
//3）针对first中数组元素*-1，在second数组中遍历，由于可能存在多个，因此我们要获得上边界和下边界
//可以使用lower_bound 和upper_bound
//	也可以直接使用equal_range
 

class Solution {
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        vector<int> firstvec;
        vector<int> secondvec;
        int result = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A.size(); j++) {
                firstvec.push_back(A[i] + B[j]);
                secondvec.push_back(C[i] + D[j]);
            }
        }

        sort(secondvec.begin(), secondvec.end());

        for (int i = 0; i < firstvec.size(); i++) {
            int findvalue = firstvec[i] * (-1);
            pair<vector<int>::iterator,vector<int>::iterator> range = equal_range(secondvec.begin(), secondvec.end(), findvalue);
            result += range.second - range.first;
        }

        return result;
    }
};
 