// 二分法，而不是从1开始
class Solution {
public:
    int mySqrt(int x) {
        long long l = 1, r = x, ret = 0;
        while (l <= r) {
            long long m = (l + r) >> 1;
            if (m <= x / m) { l = m+1; ret = m; }
            else r = m-1;
        }
        return ret;
    }
};

// ps:浮点处理，牛顿迭代法
#include <cfloat>
#include <cmath>

float sqrtf(float x) {
    float ret;
    for (float f = 1.f; true; f = ret) {
        ret = (f + x / f) / 2;
        if (std::abs(f - ret) < FLT_MIN) break;
    }
    return ret;
}