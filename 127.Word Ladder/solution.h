// 1. leetcode -- BFS
class Solution{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        //加入所有节点，访问过一次，删除一个。
        unordered_set<string> s;
        for (auto &i : wordList) s.insert(i);

        queue<pair<string, int>> q;
        //加入beginword
        q.push({beginWord, 1});

        string tmp; //每个节点的字符
        int step;    //抵达该节点的step

        while ( !q.empty() ){
            if ( q.front().first == endWord){
                return (q.front().second);
            }
            tmp = q.front().first;
            step = q.front().second;
            q.pop();

            //寻找下一个单词了
            char ch;
            for (int i = 0; i < tmp.length(); i++){
                ch = tmp[i];
                for (char c = 'a'; c <= 'z'; c++){
                    //从'a'-'z'尝试一次
                    if ( ch == c) continue;
                    tmp[i] = c ;
                    //如果找到的到
                    if (  s.find(tmp) != s.end() ){
                        q.push({tmp, step+1});
                        s.erase(tmp) ; //删除该节点
                    }
                tmp[i] = ch; //复原
                }
               
            }
        }
        return 0;
    }
};

// 2.构图 BFS
class Solution {
public:
    // 从beginWord开始转换，直到endWord，最终构成构成一个无向有环图。
    //                 hit
    //                  |
    //                 hot
    //                /   \
    //              dot -- lot
    //             /       |
    //            dog      |
    //            |  \    /
    //            |   log
    //            |  /
    //            cog
    //
    // 我们可以将图中某些重复结点的边去掉，以减少重复计算，因为我们只会选择先
    // 变换得到的单词，后续重复生成的相同单词的 路径长度肯定要相同或更大，直接
    // 跳过不影响最终的结果，最终上图可以转换成下图。
    //
    //                 hit
    //                  |
    //                 hot
    //                /   \
    //              dot   lot
    //             /       |
    //            dog     log
    //             |      /
    //             \     /
    //               cog
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int word_size = wordList[0].length(), list_size = wordList.size();
        // 构建 转换树，某个结点的孩子结点为一个集合，包含了所有能够进行一次转换得到的有效单词。
        // 按层从beginWord开始构建多叉树，直到遇到endWord，此时的层高+1即为最短路径。
        vector<set<string>> levels(list_size + 1, set<string>()); //树最高不超过字典长度
        vector<int> flags(list_size, 0);// 标记数组，用于标记哪些单词已经被 选择
        levels[0].insert(beginWord);
        for (int i = 0; i < levels.size(); i++) 
        { // 尝试添加下一层的有效单词
            for (auto it = levels[i].begin(); it != levels[i].end(); it++)
             { // 遍历当前层的每一个单词
                // 从字典中选择能够进行一次字母转换，而得到的单词
                for (int k= 0; k < list_size; k++) 
                { 
                    if (flags[k] == 1) continue;
                    int l = 0, cnt = 0;
                    while (l < word_size && cnt <= 1) 
                    {
                        if ((*it)[l] != wordList[k][l]) cnt++;
                        l++;
                    }
                    if (cnt == 1) 
                    {
                        flags[k] = 1;
                        levels[i+1].insert(wordList[k]);
                        // 此时，得到最小层数，直接return
                        if (wordList[k] == endWord) return i + 2;
                    }
                }
            }
        }
        return 0;
    }
};

//3. 先构图，后BFS
class Solution {
public:
	bool connect(const string& word1,const string &word2)//判断两个单词是否仅一个字母不同
	{
		int dif=0; //不同的字母数量
		for(int i=0;i<word1.length();i++)
		{
			if(word1[i]!=word2[i]) 
				dif++;
			if(dif>1)
				return false;
		}
		return dif==1;
	 } 
	//构建图(邻接表), graph必须为引用 
	void construct_graph(string &beginWord,vector<string> &wordList,unordered_map<string,vector<string> > &graph)
	{
		wordList.push_back(beginWord);
		for(int i=0;i<wordList.size();i++)
		for(int j=i+1;j<wordList.size();j++)//避免重复
		{
			if(connect(wordList[i],wordList[j])==true)
			{
				graph[wordList[i]].push_back(wordList[j]);
				graph[wordList[j]].push_back(wordList[i]);
			}
		} 	
	} 
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
    	unordered_map<string,vector<string> > graph;
    	construct_graph(beginWord,wordList,graph);
        queue<string> Q;
        unordered_set<string> visit;//记录已经访问过的元素
		Q.push(beginWord); 
		visit.insert(beginWord);
		int result=1;
		while(!Q.empty())
		{
			int size=Q.size();
			for(int i=0;i<size;i++) //每一次循环代表宽度增1 
			{
				string tmp=Q.front();
				Q.pop();
				vector<string> neighbors=graph[tmp]; //邻居们
				for(int i=0;i<neighbors.size();i++)
				{
					if(visit.find(neighbors[i])==visit.end())  //还没加入 
					{
						Q.push(neighbors[i]);
						visit.insert(neighbors[i]);
					}
                    if(neighbors[i]==endWord) return result+1;
				 }			
			} 
            result++;  //遍历一层则+1		
		} 
		return 0;
		 
    }
};

// 4. 数组索引构图
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        int idx_b = -1, idx_e = -1;
        for (int i = 0; i < wordList.size(); i ++) {
            if (wordList[i] == beginWord) idx_b = i;
            if (wordList[i] == endWord) idx_e = i;
        }
        if (idx_e == -1) return 0;
        if (idx_b == -1) {
            wordList.push_back(beginWord);
            idx_b = wordList.size() - 1;
        }
        int n = wordList.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int cnt = 0;
                for (int k = 0; k  < beginWord.size(); k ++) {
                    if (wordList[i][k] != wordList[j][k]) cnt ++;
                    if (cnt > 1) break;
                }
                if (cnt == 1) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        queue<pair<int, int>> qe;
        qe.push({idx_b, 1});
        vector<bool> st(n, false);
        st[idx_b] = true;
        while (qe.size()) {
            auto ele = qe.front();
            qe.pop();
            int node = ele.first, dis = ele.second;
            for (auto x : g[node] ) {
                if (st[x]) continue;
                if (x == idx_e) return dis + 1;
                qe.push({x, dis + 1});
                st[x] = true;
            }
        }
        return 0;
    }
};
