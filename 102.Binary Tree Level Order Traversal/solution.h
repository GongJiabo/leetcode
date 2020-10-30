// from pezy
//思路应该是非常顺其自然的，需要一个 deque 或者 queue 来做缓存，由于昨晚刚学了CP5上的 deque，所以就选择了前者。
//通过迭代，将所有下一层级的节点放到 deque 中去， 同时将这一层节点的 value 放到 vector 中去。
//唯一需要注意的是，deque 的长度一直在变， 所以迭代的时候，不能用 q.size() 作为一个恒定的标杆，应该多用一个局部变量，如 n ，来记录当前的长度。
//这块第一次考虑的时候，想复杂了，竟然弄了两个 deque 来交替，有点粗暴，但却让我 2 分钟解出，在手机上 AC 了。后来想想，其实控制好长度，一个 deque 完全可以胜任。
//
//我的理解:在while大循环中，用到for循环去遍历每一层的元素，其中for循环次数即q.zie()，即当前队列中的元素个数(全为一层的)。
#include <vector>
#include <deque>
#include <cstddef>

using std::vector; using std::deque;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> retv;
        if (root)
        {
            deque<TreeNode*> q{root}; 
            while (!q.empty())
            {
                vector<int> v;
                for (decltype(q.size()) i=0, n=q.size(); i!=n; ++i)
                {
                    TreeNode *node = q.front(); q.pop_front();
                    v.push_back(node->val);
                    if (node->left) q.push_back(node->left);
                    if (node->right) q.push_back(node->right);
                }
                retv.push_back(v);
            }
        }
        return retv;
    }
};

// leetcode
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> ret;
        if (!root) {
            return ret;
        }

        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();
            ret.push_back(vector <int> ());
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = q.front(); q.pop();
                ret.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return ret;
    }
};
 