/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 创建一个队列，队列中的元素为queue<pair<TreeNode*,int>>，用于保存每个结点与对应的层次
// 注意结果数组中，vector.size刚好等于当前层次时，说明改结点为该层次的第一个结点，创建vector子元素。
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*,int>> qlevel;
        vector<vector<int>> res;
        //
        if (root==NULL) return res;
        qlevel.push(make_pair(root, 0));
        while (!qlevel.empty())
        {
            //取队首的元素
            TreeNode* p = (qlevel.front()).first;
            int n = (qlevel.front()).second;
            qlevel.pop();
            //判断当前层是否已经存入res，若没有则先存入空vector
            if (n == res.size())
                res.push_back(vector<int>{});
            res[n].push_back(p->val);
            //左右孩子入队
            if (p->left) qlevel.push(make_pair(p->left, n + 1));
            if (p->right) qlevel.push(make_pair(p->right, n + 1));
        }
        return res;
    }
};