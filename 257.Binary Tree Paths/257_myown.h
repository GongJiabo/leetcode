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
    vector<string> res;
    bool isLeafNode(TreeNode* p)
    {
        return !p->left && !p->right;
    }
    void dfs(TreeNode* root, string s)
    {
        if(!root)
            return;
        s+=to_string(root->val);
        s+="->";
        if(isLeafNode(root))
        {
            s.pop_back();
            s.pop_back();
            res.push_back(s);
        }
        if(root->left) dfs(root->left, s);
        if(root->right) dfs(root->right, s);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        dfs(root, "");
        return res;
    }
};