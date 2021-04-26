/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isMirror(TreeNode* p, TreeNode* q)
    {
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        while(!que.empty())
        {
            // 连续取两个队首元素判断是否相等
            TreeNode* u = que.front();
            que.pop();
            TreeNode* v = que.front();
            que.pop();
            //
            if(!u && !v) continue;
            // 注意先判断u、v是否存在
            if( (!u || !v) || u->val != v->val )
                return false;
            //
            que.push(u->left);
            que.push(v->right);
            //
            que.push(u->right);
            que.push(v->left);
        }
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return isMirror(root, root);
    }
};