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
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder)
    {
        if(preorder.size()==0)
            return NULL;
         // 后序遍历数组最后一个元素，就是当前的中间节点
        int rootValue = preorder[0];
        TreeNode* root = new TreeNode(rootValue);

        // 叶子节点
        if (preorder.size() == 1) return root;

        // 找到中序遍历的切割点
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) break;
        }

        // 切割中序数组
        // 左闭右开区间：[0, delimiterIndex)
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        // [delimiterIndex + 1, end)
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end() );

        // preorder 舍弃头元素
        // 切割先序数组
        // 依然左闭右开，注意这里使用了左中序数组大小作为切割点
        // [1, 1 + leftInorder.size)
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + leftInorder.size() + 1);
        // [1 + leftInorder.size(), end)
        vector<int> rightPreorder(preorder.begin() + leftInorder.size() + 1, preorder.end());

        root->left = traversal(leftPreorder, leftInorder);
        root->right = traversal(rightPreorder, rightInorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 0 || preorder.size() == 0) return NULL;
        // 左闭右开的原则
        return traversal(preorder, inorder);
    }
};