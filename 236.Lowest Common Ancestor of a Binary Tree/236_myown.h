/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        assert( p && q);
        //
        if(!root)
            return NULL;
        // p、q在root右侧
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right,p,q);
        // p、q在root左侧
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left,p,q);
        // p、q在root两侧，则root为祖先
        return root;
    }
};