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
    int minDepth(TreeNode* root) {
        // 为空节点时，返回0
        if(!root) 
            return 0;
        // 左右孩子都为空时，返回1
        if(!root->left && !root->right)
            return 1;
        // 当左孩子或者右孩子不都为空时，计算左右子树的最小深度
        int ld = minDepth(root->left);
        int rd = minDepth(root->right);
        // 当左孩子或右孩子有一个为空时，深度为ld+rd+1(ld或rd为0)
        if(!root->left || !root->right) return ld+rd+1;
        
        // 最后一种情况，也就是左右孩子都不为空，返回最小深度+1即可
        return (ld<rd?ld:rd)+1;  
    }
};

// 简化版
class Solution {
public:
    int minDepth(TreeNode* root) {
        // 为空节点时，返回0
        if(!root) 
            return 0;

        int ld = minDepth(root->left);
        int rd = minDepth(root->right);
        
        //1.如果左孩子和右孩子有为空的情况，直接返回ld+rd+1
        //2.如果都不为空，返回较小深度+1
        return (!root->left || !root->right)? ld+rd+1 : (ld<rd?ld:rd)+1;  
    }
};