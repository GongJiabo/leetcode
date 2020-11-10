// 1. 超出时间限制 应该是求了所有的解，没有剪支
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        vector<vector<string>> res;
        // 设置开始于结束字符串的索引
        int idx_b = -1, idx_e = -1;
        for (int i = 0; i < wordList.size(); i++)
        {
            if (wordList[i] == beginWord) idx_b = i;
            if (wordList[i] == endWord) idx_e = i;
        }
        //
        if (idx_b == -1)
        {
            wordList.push_back(beginWord);
            idx_b = wordList.size() - 1;
        }
        if (idx_e == -1)
            return res;
        //
        // 用矩阵构造图的邻接表
        int n = wordList.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // wordList[i]与wordlList[j]的不同字母个数
                int cnt = 0;
                for (int k = 0; k < beginWord.size(); k++)
                {
                    if (wordList[i][k] != wordList[j][k])
                        cnt++;
                    if (cnt > 1) break;
                }
                if (cnt == 1)
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }

            }
        }
        //入队检索
        queue<vector<int>> qe;
        qe.push(vector<int>{idx_b});

        int min_size = wordList.size() + 1;

        while (qe.size())
        {
            // 取队列第一个路径
            auto path = qe.front();
            qe.pop();
            int last = path.back();
            //
            // 剪支
            if (path.size() > min_size)
                continue;
            
            if (last == idx_e && path.size()<=min_size)
            {
                min_size = path.size();
                vector<string> tmp;
                for (int i = 0; i < path.size(); i++)
                    tmp.push_back(wordList[path[i]]);
                res.push_back(tmp);
            }
            else
            {
                for (auto x : g[last])
                {
                    if (find(path.begin(), path.end(), x) != path.end()) 
                        continue;

                    vector<int> tmp(path.begin(), path.end());
                    tmp.push_back(x);
                    qe.push(tmp);
                }
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

// 2. 使用cost数组，记录开始字符串到其他字符串的“距离”
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        vector<vector<string>> res;
        // 设置开始于结束字符串的索引
        int idx_b = -1, idx_e = -1;
        for (int i = 0; i < wordList.size(); i++)
        {
            if (wordList[i] == beginWord) idx_b = i;
            if (wordList[i] == endWord) idx_e = i;
        }
        //
        if (idx_b == -1)
        {
            wordList.push_back(beginWord);
            idx_b = wordList.size() - 1;
        }
        if (idx_e == -1)
            return res;
        //
        // 用矩阵构造图的邻接表
        int n = wordList.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // wordList[i]与wordlList[j]的不同字母个数
                int cnt = 0;
                for (int k = 0; k < beginWord.size(); k++)
                {
                    if (wordList[i][k] != wordList[j][k])
                        cnt++;
                    if (cnt > 1) break;
                }
                if (cnt == 1)
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }

            }
        }
        //入队检索
        queue<vector<int>> qe;
        qe.push(vector<int>{idx_b});

        //int min_size = wordList.size() + 1;
        vector<int> cost(wordList.size(), INT_MAX);
        cost[idx_b] = 0;

        while (qe.size())
        {
            // 取队列第一个路径
            auto path = qe.front();
            qe.pop();
            //
            int last = path.back();
            // 剪支
            //if (path.size() > min_size)
            //    continue;
            //
            if (last == idx_e)
            {
                //min_size = path.size();
                vector<string> tmp;
                for (int i = 0; i < path.size(); i++)
                    tmp.push_back(wordList[path[i]]);
                res.push_back(tmp);
            }
            else
            {
                for (auto x : g[last])
                {
                    //if (find(path.begin(), path.end(), x) != path.end()) 
                        //continue;
                    if (cost[last] + 1 <= cost[x])
                    {
                        cost[x] = cost[last] + 1;
                        vector<int> tmp(path.begin(), path.end());
                        tmp.push_back(x);
                        qe.push(tmp);
                    }
                }
            }
        }
        return res;
    }
};