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
    int res;
    bool isLeafNode(TreeNode* p)
    {
        return (!p->left) && (!p->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        // 左孩子存在
        if(root->left)
        {
            // 左孩子是叶子结点
            if(isLeafNode(root->left))
                res+=root->left->val;
            else
                sumOfLeftLeaves(root->left);
        }
        // 右孩子存在，且右孩子不是叶子结点
        if(root->right && !isLeafNode(root->right))
            sumOfLeftLeaves(root->right);
        return res;
    }
};