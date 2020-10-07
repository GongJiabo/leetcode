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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return vpre;
        else
        {
            vpre.push_back(root->val);
            vpre = preorderTraversal(root->left);
            vpre = preorderTraversal(root->right);
        }
        return vpre;
    }
private:
    vector<int> vpre;
};

//2. 迭代(栈)
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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*> treeStack;
        if (!root) return {};
        //
        treeStack.push(root);
        while (!treeStack.empty())
        {
            TreeNode* stop = treeStack.top();
            vpre.push_back(stop->val);
            treeStack.pop();
            if(stop->right) 
                treeStack.push(stop->right);
            if(stop->left)
                treeStack.push(stop->left);
        }
        return vpre;
    }
private:
    vector<int> vpre;
};