// 超出时间限制
// 如何设置visited数组？
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        //
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 0));
        
        // 记录是否转换过
        unordered_set<string> s;
        for (auto& i : wordList) 
            s.insert(i);


        while (!q.empty())
        {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            //
            if (word == endWord)
                return step + 1;
            else if (step >= wordList.size())
                return 0;
            //
            for (int i = 0; i < wordList.size(); i++)
            {
                if (differenceNum(word, wordList[i]) == 1)
                {
                    if (s.find(wordList[i]) != s.end())
                    {
                        q.push(make_pair(wordList[i], step + 1));
                        s.erase(wordList[i]);
                    }
                }
            }
        }
        return 0;
    }

    int differenceNum(string& s1, string& s2)
    {
        if (s1.size() != s2.size()) 
            return -1;
        //
        int count = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
                count++;
        }
        return count;
    }
};