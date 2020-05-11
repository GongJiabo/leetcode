/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//1.DFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root!=nullptr)
        {
            int ld = maxDepth(root->left);
            int rd = maxDepth(root->right);
            return max(ld,rd) + 1;
        }       
        else return 0;
    }
};


//2.BFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int ans = 0;
        if (root != nullptr) q.push(root);
        while (!q.empty()) {
            for (int i = q.size() - 1; i >= 0; --i) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            ++ans;
        }
        return ans;
    }
};
