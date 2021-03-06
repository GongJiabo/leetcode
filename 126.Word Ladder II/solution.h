// leetcode
const int INF = 1 << 20;

class Solution {
private:
    unordered_map<string, int> wordId;
    vector<string> idWord;
    vector<vector<int>> edges;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int id = 0;
        for (const string& word : wordList) {
            if (!wordId.count(word)) {
                wordId[word] = id++;
                idWord.push_back(word);
            }
        }
        if (!wordId.count(endWord)) {
            return {};
        }
        if (!wordId.count(beginWord)) {
            wordId[beginWord] = id++;
            idWord.push_back(beginWord);
        }
        edges.resize(idWord.size());
        for (int i = 0; i < idWord.size(); i++) {
            for (int j = i + 1; j < idWord.size(); j++) {
                if (transformCheck(idWord[i], idWord[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        const int dest = wordId[endWord];
        vector<vector<string>> res;
        queue<vector<int>> q;
        vector<int> cost(id, INF);
        q.push(vector<int>{wordId[beginWord]});
        cost[wordId[beginWord]] = 0;
        while (!q.empty()) {
            vector<int> now = q.front();
            q.pop();
            int last = now.back();
            if (last == dest) {
                vector<string> tmp;
                for (int index : now) {
                    tmp.push_back(idWord[index]);
                }
                res.push_back(tmp);
            } else {
                for (int i = 0; i < edges[last].size(); i++) {
                    int to = edges[last][i];
                    if (cost[last] + 1 <= cost[to]) {
                        cost[to] = cost[last] + 1;
                        vector<int> tmp(now);
                        tmp.push_back(to);
                        q.push(tmp);
                    }
                }
            }
        }
        return res;
    }

    bool transformCheck(const string& str1, const string& str2) {
        int differences = 0;
        for (int i = 0; i < str1.size() && differences < 2; i++) {
            if (str1[i] != str2[i]) {
                ++differences;
            }
        }
        return differences == 1;
    }
};

// bfs + dfs
#include<queue>
class Solution {
public:
    
    vector<string> words;
    vector<vector<int>> ff;
    vector<vector<string>> res;
    vector<string> t;
    
    
    void dfs(int i){   // dfs回溯答案
        if(i == words.size() - 1){
            res.push_back(t);
            return;
        }
        for(auto x:ff[i]){
            t.push_back(words[x]);
            dfs(x);
            t.pop_back();
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        wordList.push_back(beginWord);
        int id = -1;
        for(int i = 0; i < wordList.size(); i ++){ // 查找目标word的下标
            if(wordList[i] == endWord){
                id = i;
                break;
            }
        }
        if(id == -1) return ans;   // 不存在则直接返回
        int n = wordList.size();
        vector<vector<int>> es(n, vector<int>()), fa(n, vector<int>());  
        vector<bool> st(n, false);
        for(int i = 0; i < n; i ++){  // 构图
            for(int j = i + 1; j < n; j ++){
                int t = 0;
                for(int k = 0; k < wordList[i].size(); k ++){
                    if(wordList[i][k] != wordList[j][k]){
                        t += 1;
                    }
                    if(t > 1) break;
                }
                if(t == 1) es[i].push_back(j), es[j].push_back(i);
            }
        }
        
        queue<int> q;
        vector<int> dis(n, 0x3f3f3f3f);
        dis[n-1] = 0;
        q.push(n - 1);
        st[n - 1] = true;
        while(q.size()){   // 广搜，并记录所有的父节点
            queue<int> t;
            while(q.size()){
                auto it = q.front();
                q.pop();
                for(auto x:es[it]){
                    if(dis[it] + 1 <= dis[x]){
                        fa[x].push_back(it);
                        dis[x] = dis[it] + 1;
                        if(!st[x]){
                            st[x] = true;
                            t.push(x);
                        }
                    }
                }
            }
            if(st[id]) break;
            q = t;
        }
        if(!st[id]) return ans;
        
        words = wordList;
        ff = fa;
        t.push_back(wordList[id]);
        dfs(id);
        for(auto &x: res){  // 路径是相反的，所以需要reverse
            reverse(x.begin(), x.end());
        }
        return res;
    }
};
