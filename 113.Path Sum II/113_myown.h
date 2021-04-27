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
    bool isLeafNode(TreeNode* p)
    {
        return !p->left && !p->right;
    }
    void dfs(TreeNode* root, int targetSum, vector<vector<int>>& res, vector<int> tmp)
    {
        if(!root)
            return;
        tmp.push_back(root->val);
        if(isLeafNode(root) && targetSum==root->val)
        {
            res.push_back(tmp);
        }
        if(root->left) dfs(root->left, targetSum-root->val, res, tmp);
        if(root->right) dfs(root->right, targetSum-root->val, res, tmp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> tmp;
        vector<vector<int>> res;
        if(!root)
            return res;
        //
        dfs(root, targetSum, res, tmp);
        return res;
    }
};