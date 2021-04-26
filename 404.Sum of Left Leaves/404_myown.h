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

    bool isLeafNode(TreeNode* node) {
        // 左右孩子均不存在
        return !node->left && !node->right;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(root==nullptr || isLeafNode(root))
            return 0;
        //
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        while(!q.empty())
        {
            //
            int sz = q.size();
            for(int i=0;i<sz;++i)
            {
                TreeNode* tmp = q.front();
                q.pop();
                // 如果左孩子是叶子结点
                if(tmp->left)
                {
                    if(isLeafNode(tmp->left))
                        sum+=tmp->left->val;
                    else
                        q.push(tmp->left);
                }
                // 如果右孩子存在且右孩子不是叶子结点
                if(tmp->right && !isLeafNode(tmp->right))
                {
                    q.push(tmp->right);
                }
            }
        }
        return sum;
    }
};