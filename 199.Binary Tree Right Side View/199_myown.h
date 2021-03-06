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
    vector<int> rightSideView(TreeNode* root)
    {
        vector<vector<int>> vlevel;
        vector<int> res;
        if (!root)
            return res;
        //
        queue<TreeNode*> qlevel;
        qlevel.push(root);
        //根节点为第一层
        while (!qlevel.empty())
        {
            int size = qlevel.size();
            vector<int> temp;
            for (int i = 0; i < size; i++)
            {
                TreeNode* p = qlevel.front();
                qlevel.pop();
                temp.push_back(p->val);
                if (p->left)
                    qlevel.push(p->left);
                if (p->right)
                    qlevel.push(p->right);
            }
            vlevel.push_back(temp);
        }
        //取每层的最右边的结点；
        for (auto i = 0; i < vlevel.size(); i++)
            res.push_back(*(vlevel[i].end() - 1));
        return res;
    }
};