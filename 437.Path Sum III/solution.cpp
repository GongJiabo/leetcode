// 回溯 + 前缀和
// 前缀和的概念：
// 一个节点的前缀和就是该节点到根之间的路径和。
// 前缀和的意义：
// 因为对于同一路径上的两个节点，上面的节点是下面节点的祖先节点，所以其前缀和之差即是这两个节点间的路径和（不包含祖先节点的值）。
// 哈希map的使用：
// key是前缀和， value是该前缀和的节点数量，记录数量是因为有出现复数路径的可能。
// 回溯的意义：
// 因为只有同一条路径上的节点间（节点和其某一祖先节点间）的前缀和做差才有意义。所以当前节点处理完之后，需要从map中移除这一个前缀和，然后再进入下一个分支路径。
class Solution {
private:
    unordered_map<int, int> prefix;         // <前缀和，其出现次数>
    void dfs(TreeNode* root, int sum, int cur_sum, int& res)
    {
        if (!root) return;
        cur_sum += root->val;               // 更新前缀和
        // 当前路径中存在以当前节点为终点的和为sum的子路径
        if (prefix.find(cur_sum - sum) != prefix.end())
            res += prefix[cur_sum - sum];
        prefix[cur_sum]++;                  // 将当前节点加入路径
        dfs(root->left, sum, cur_sum, res); // 在其左子树中递归寻找
        dfs(root->right, sum, cur_sum, res);// 在其右子树中递归寻找
        prefix[cur_sum]--;                  // 回溯
    }
public:
    int pathSum(TreeNode* root, int sum) 
    {
        int res = 0;    // 满足条件的路径数量
        prefix[0] = 1;  // 前缀和为0的路径只有一条：哪个节点都不选
        dfs(root, sum, 0, res);
        return res;
    }
};