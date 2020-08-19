//首先遍历A,B两个数组的元素，对相加构成的值存入unordered_map
//unordered_map中，键key和值(查找值)，值value为出现的次数，便于求解最终结果。
//时间、空间复杂度均为O(N²)

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> record;
        int res = 0;
        //
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < B.size(); j++)
                record[A[i] + B[j]]++;
        //
        for (int i = 0; i < C.size(); i++)
            for (int j = 0; j < D.size(); j++)
                if (record.find(-C[i] - D[j]) != record.end())
                    res += record[-C[i] - D[j]];
        //
        return res;
    }
};