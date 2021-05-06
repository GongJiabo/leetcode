// 同235的solution
// 找到从根节点到p、q节点的路径，寻找最后一个共同的祖先。
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
    vector<TreeNode*> tmp;
    vector<vector<TreeNode*>> path;
    void getPath(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root)   
            return;
        //
        tmp.push_back(root);
        if(root == p || root == q )
            path.push_back(tmp);
        //
        getPath(root->left, p,q);
        getPath(root->right,p,q);
        tmp.pop_back();
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q)
            return nullptr;
        getPath(root,p,q);
        TreeNode* ancestor;
        for(int i=0;i<path[0].size() && i<path[1].size();++i)
        {
            if(path[0][i]==path[1][i])
                ancestor = path[0][i];
            else
                break;
        }
        return ancestor;
    }
};