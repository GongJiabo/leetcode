// 递归
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
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;
        // 
        int res = findPath(root,targetSum);
        res+=pathSum(root->left,targetSum);
        res+=pathSum(root->right,targetSum);
        return res;
    }

    // 以当前结点p为根节点的路径
    int findPath(TreeNode* p, int target)
    {
        if(!p)
            return 0;
        int res=0;
        // 不能直接返回，可能存在正负相消的情况
        if(p->val == target)
            res+=1;
        //
        if(p->left) res+=findPath(p->left, target-p->val);
        if(p->right) res+=findPath(p->right, target-p->val);
        //
        return res;
    }
};