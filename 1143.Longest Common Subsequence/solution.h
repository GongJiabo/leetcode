// 动态规划(空间优化，一位数组)
// 每次计算新的一行的时候, 用到的都是上一行或者本行之前算过的数据, 所以可以优化到一维数组
// 比如计算dp[3][2]的时候, 用到的可能有他的左上角, 正上方, 和左侧数据. 左侧数据是在同一行, 上方数据还未被覆盖,还是上一行的老数据,
// 所以都可以直接用, 这里唯一注意就是左上方的数据, 因为在计算前一列的时候会被覆盖, 需要在被覆盖之前保存下旧值
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.empty() || text2.empty())
            return 0;
        int n = text1.size();
        int m = text2.size();
        vector<int> dp(m + 1, 0);
        for (int i = 1; i <= n; i++) {
            int upLeft = dp[0]; // 每行开始的时候需要更新下upleft, 这里其实每次都是0
            for (int j = 1; j <= m; j++) {
                int tmp = dp[j]; // 记录未被覆盖之前的dp[j], 它会在计算 j+1的时候作为upLeft用到
                if (text1[i - 1] == text2[j - 1])
                    dp[j] = upLeft + 1;
                else
                    dp[j] = max(dp[j - 1], dp[j]);
                upLeft = tmp; // 更新upLeft
            }
        }
        return dp[m];
    }
};
