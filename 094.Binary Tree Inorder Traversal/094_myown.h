//1. 递归
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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return{};
        inorderTraversal(root->left);
        vin.push_back(root->val);
        inorderTraversal(root->right);
        return vin;
    }
private:
    vector<int> vin;
};

//2. 迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> treeStack;
        if (!root) return {};
        //
        while (!treeStack.empty() || root)
        {
            while (root != NULL)
            {
                treeStack.push(root);
                root = root->left;
             }
            root = treeStack.top();
            treeStack.pop();
            vin.push_back(root->val);
            root = root->right;
        }
        return vin;
    }
private:
    vector<int> vin;
};