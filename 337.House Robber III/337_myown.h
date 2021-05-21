// 递归(时间超限)
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
    int rob(TreeNode* root) {
        // 空节点
        if(!root)
            return 0;
        int money = root->val;
        // 从根节点开始（爷爷节点），不偷2个孩子节点，偷4个孙子节点
        // 左孩子存在
        if(root->left)
            money += rob(root->left->left) + rob(root->left->right);
        // 右孩子存在
        if(root->right)
            money += rob(root->right->left) + rob(root->right->right);
        
        // 和偷两个孩子中取较大的
        return max(money, rob(root->left)+rob(root->right));

    }
};

// 递归(空间优化，使用map存储)
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
private:
    map<TreeNode*, int> m;
public:
    int rob(TreeNode* root) {
        // 空节点
        if(!root)
            return 0;
        if(m.find(root)!=m.end())
            return m[root];
        int money = root->val;
        // 从根节点开始（爷爷节点），不偷2个孩子节点，偷4个孙子节点
        // 左孩子存在
        if(root->left)
            money += rob(root->left->left) + rob(root->left->right);
        // 右孩子存在
        if(root->right)
            money += rob(root->right->left) + rob(root->right->right);
        
        // 和偷两个孩子中取较大的
        int res = max(money, rob(root->left)+rob(root->right));
        m[root] = res;
        return res;
    }
};