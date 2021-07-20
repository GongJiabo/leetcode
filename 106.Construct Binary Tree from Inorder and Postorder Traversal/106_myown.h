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
    TreeNode* createTree(vector<int>& inorder, vector<int>& postorder)
    {
        // 后续遍历数组为空, 没有根节点, 返回null
        if(postorder.size() == 0)
            return NULL;
        // 锁定根结点
        int rootval = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode(rootval);
        // 找到根结点在中序遍历中的位置
        int rootInorder;
        for(rootInorder = 0; rootInorder < inorder.size(); ++rootInorder)
            if(inorder[rootInorder] == rootval)
                break;
        // 切割中序数组 [0, rootInorder) [rootInorder+1, inorder.size())
        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootInorder);
        vector<int> rightInorder(inorder.begin() + rootInorder + 1, inorder.end());

        // 切割后序数组  [0, leftInorder.size)  [leftInorder.size(), end)
        // 舍弃已经提取的root结点
        postorder.resize(postorder.size() - 1);
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        // 递归
        root->left = createTree(leftInorder, leftPostorder);
        root->right = createTree(rightInorder, rightPostorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if(inorder.empty() || postorder.empty())
            return NULL;
        return createTree(inorder, postorder);
    }
};