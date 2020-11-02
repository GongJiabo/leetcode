//1. BFS
class Solution {
public:
   vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> res;
        //
        if (!root) 
            return res;
        queue<TreeNode*> qlevel;
        qlevel.push(root);
        //BFS
        while (!qlevel.empty())
        {
            vector<int> temp{};
            int size = qlevel.size();
            //对当前队列中的元素进行BFS
            for (int i = 0; i < size; i++)
            {
                //取队首的元素
                TreeNode* p = qlevel.front();
                qlevel.pop();
                temp.push_back(p->val);
                //左右孩子入队
                if (p->left)
                    qlevel.push(p->left);
                if (p->right)
                    qlevel.push(p->right);
            }
            //
            res.push_back(temp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//2. pair 
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
               queue<pair<TreeNode*,int>> qlevel;
        vector<vector<int>> res;
        //
        if (!root) 
            return res;
        qlevel.push(make_pair(root, 0));
        while (!qlevel.empty())
        {
            //取队首的元素
            TreeNode* p = (qlevel.front()).first;
            int n = (qlevel.front()).second;
            qlevel.pop();
            //判断当前层是否已经存入res，若没有则先存入空vector
            if (n == res.size())
                res.push_back(vector<int>{});
            res[n].push_back(p->val);
            //左右孩子入队
            if (p->left) 
                qlevel.push(make_pair(p->left, n + 1));
            if (p->right)
                qlevel.push(make_pair(p->right, n + 1));
        }
        reverse(res.begin(),res.end());
        return res; 
    }
};