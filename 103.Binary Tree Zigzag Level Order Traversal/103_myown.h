/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
 vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        //
        queue<TreeNode*> qlevel;
        qlevel.push(root);
        //根节点为第一层
        int level = 1;
        while (!qlevel.empty())
        {
            int size = qlevel.size();
            vector<int> temp;
            for (int i = 0; i < size; i++)
            {
                TreeNode* p = qlevel.front();
                qlevel.pop();
                temp.push_back(p->val);
                //
                if (p->left)
                    qlevel.push(p->left);
                if (p->right)
                    qlevel.push(p->right);
            }
            if(level++ % 2 == 0)
                reverse(temp.begin(),temp.end());
            res.push_back(temp);
        }
        return res;
    }
};