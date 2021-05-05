// DFS
class Solution {
public:

    void dfs(TreeNode* root, vector<int> tmp, vector<vector<int>>& res)
    {
        if(!root)
            return;
        tmp.push_back(root->val);
        if(!root->left && !root->right)
            res.push_back(tmp);
        //
        dfs(root->left,tmp,res);
        dfs(root->right,tmp,res);
    }

    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        //
        vector<int> v;
        vector<vector<int>> vv;
        dfs(root,v,vv);
        //
        int res=0;
        for(int i=0;i<vv.size();++i)
        {
            int level=vv[i].size();
            for(int j=0;j<level;++j)
                res+=vv[i][j]*pow(10,level-j-1);
        }
        return res;
    }
};

//
class Solution {
public:
    int dfs(TreeNode* root, int prevSum) {
        if (root == nullptr) {
            return 0;
        }
        int sum = prevSum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return sum;
        } else {
            return dfs(root->left, sum) + dfs(root->right, sum);
        }
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};
