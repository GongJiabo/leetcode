#include <iostream>
using std::swap;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i=0; i<n; ++i)
            while (A[i]>0 && A[i]<=n && A[i]!=A[A[i]-1]) // 前两个条件限定范围，最后是如果序号位置的值与当前值一样，交换无意义
                swap(A[i], A[A[i]-1]);
        for (int i=0; i<n; ++i)                         
            if (A[i] != i+1) return i+1;                 // 最后的检查，一旦发现与序号不符，立刻返回
        return n+1;                                     // 如果都相符，那么返回 n+1
    }
};
