// 1. DFS遍历所有树节点，但没有使用到完全二叉树的特性
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
    int cnt;
public:
    void dfs(TreeNode* p)
    {
        if(!p)
            return;
        ++cnt;
        dfs(p->left);
        dfs(p->right);
    }
    int countNodes(TreeNode* root) {
        this->cnt = 0;
        dfs(root);
        return cnt;
    }
};

//2. 利用完全二叉树性质遍历
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
    int countLevels(TreeNode* p)
    {
        int level=0;
        while(p)
        {
            ++level;
            p = p->left;
        }
        return level;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int left_level = countLevels(root->left);
        int right_level = countLevels(root->right);
        if(left_level == right_level)   // 说明左子树是满二叉树
            return countNodes(root->right) + (1 << left_level);
        else    // 说明左子树高，右子树是满二叉树
            return countNodes(root->left) + (1 << right_level);
    }
};
