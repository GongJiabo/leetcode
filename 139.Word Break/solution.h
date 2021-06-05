// 字典树+DFS
class Solution {
public:
    struct Trie {
        bool isEnd;
        Trie* next[26];
        Trie() {
            this->isEnd = false;
            memset(this->next, 0, sizeof(this->next));
        }
    };
    void buildTrie(vector<string>& wordDict, Trie* head)
    {
        for (auto str : wordDict) {
            Trie* temp = head;
            for (auto ch : str) {
                if (temp->next[ch - 'a'] == nullptr) {
                    temp->next[ch - 'a'] = new Trie[1];
                }
                temp = temp->next[ch - 'a'];
            }
            temp->isEnd = true;
        }
    }
    bool dfs(string s, int pos, Trie* head, vector<bool>& visited)
    {
        if (visited[pos]) {
            return false;
        }
        Trie* temp = head;
        int i;
        for (i = pos; i < s.size(); i++) {
            if (i != pos && temp->isEnd) {
                if (dfs(s, i, head, visited)) {
                    return true;
                }
            }
            if (temp->next[s[i] - 'a'] == nullptr) {
                break;
            }
            temp = temp->next[s[i] - 'a'];
        }
        if (i == s.size() && temp->isEnd) {
            return true;
        }
        visited[pos] = true;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie head;

        buildTrie(wordDict, &head);
        vector<bool> visited(s.size(), false);
        return dfs(s, 0, &head, visited);
    }
};

// 2.DP
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set <string> ();
        for (auto word: wordDict) {
            wordDictSet.insert(word);
        }

        auto dp = vector <bool> (s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};