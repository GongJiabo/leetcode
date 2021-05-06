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
  /*
  One step right and then always left
  */
int successor(TreeNode* root) {
    root = root->right;
    while (root->left != nullptr) 
        root = root->left;
    return root->val;
}

/*
One step left and then always right
*/
int predecessor(TreeNode* root) {
    root = root->left;
    while (root->right != nullptr) root = root->right;
    return root->val;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return nullptr;

    // delete from the right subtree
    if (key > root->val) root->right = deleteNode(root->right, key);
    // delete from the left subtree
    else if (key < root->val) root->left = deleteNode(root->left, key);
    // delete the current node
    else {
      // the node is a leaf
      if (root->left == nullptr && root->right == nullptr) 
        root = nullptr;
      // the node is not a leaf and has a right child
      else if (root->right != nullptr) {
        root->val = successor(root);
        root->right = deleteNode(root->right, root->val);
      }
      // the node is not a leaf, has no right child, and has a left child    
      else {
        root->val = predecessor(root);
        root->left = deleteNode(root->left, root->val);
      }
    }
    return root;
  }
};
