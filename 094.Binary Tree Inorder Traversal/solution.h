//******* 二叉树遍历 ********//
//  递归法
//1. 先序遍历 
class Solution {
public:
    vector<int> ans;
    void preorder(TreeNode* root){
        if(root == NULL) return;
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return ans;
    }
};

//2. 中序遍历 
class Solution {
public:
    vector<int> ans;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
       inorder(root);
       return ans; 
    }
};

//3. 后序遍历
class Solution {
public:
    vector<int> ans;
    void postorder(TreeNode* root){
        if(root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
    }
};

//  迭代算法 - 栈(注意入栈的顺序与遍历顺序相反)
//1.1 先序遍历
//先把右节点压入栈中，再把左节点压入栈中
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        stack<TreeNode*> s;
        vector<int> ans;
        s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top();
            ans.push_back(node->val);
            s.pop();
            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
        }
        return ans;
    }
};

//1.2 先序遍历
//把先遍历所有的左子节点，然后判断右子节点是否为空，继续遍历，但是这样效率会有些低，因为会重复遍历一遍已经访问过的节点让他们出栈
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode* tmp = root;
        while(!s.empty() || tmp){
            while(tmp){
                s.push(tmp);
                ans.push_back(tmp->val);
                tmp = tmp->left;
            }
            TreeNode* node = s.top();
            s.pop();
            tmp = node->right;
        }
        return ans;
    }
};

//2. 中序遍历
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode* tmp = root;
        while(!s.empty() || tmp){
            while(tmp){
                s.push(tmp);
                tmp = tmp->left;
            }
            TreeNode* node = s.top();
            s.pop();
            ans.push_back(node->val);
            tmp = node->right;
        }
        return ans;
    }
};


//3.1 后序遍历
//首先我们知道后序是先左子树，再右子树，再根节点，如果我们先根节点，再右子树，再左子树，得到的结果刚好是反过来的;
//而先根节点，再右子树，再左子树和先序遍历的先根节点，再左子树，再右子树，其实很类似，只要把左右子树交换看就ok了，所以模仿先序的代码，可以写出后序的代码如下：
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        stack<TreeNode*> s;
        vector<int> ans;
        s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top();
            ans.push_back(node->val);
            s.pop();
            if(node->left) s.push(node->left);
            if(node->right) s.push(node->right);
        }
        /******* reverse *******/
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//3.2
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode* tmp = root;
        while(!s.empty() || tmp){
            while(tmp){
                s.push(tmp);
                ans.push_back(tmp->val);
                tmp = tmp->right;
            }
            TreeNode* node = s.top();
            s.pop();
            tmp = node->left;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

