class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) 
	{
		int row = board.size();
		if (row == 0) return false;
		int col = board[0].size();
		int len = word.size();
		//
		vector<vector<bool>> check;
		for (int i = 0; i < row; i++)
		{
			vector<bool> temp;
			for (int j = 0; j < col; j++)
				temp.push_back(false);
			check.push_back(temp);
		}
		//对所有单位进行DFS
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				if (DFS(board, i, j, word, 0, check))
					return true;
		}
		return false;
		//
	}
	bool DFS(vector<vector<char>> &board, int i, int j, string word, int n, vector<vector<bool>>& check)
	{
		//检测范围
		if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || check[i][j])
			return false;
		//监测是否相等
		if (board[i][j] != word[n]) return false;

		//检测到最后，返回答案
		if (n == word.size() - 1)
		{
			return board[i][j] == word[n];
		}

		//DFS
		check[i][j] = true;
		bool found = DFS(board, i - 1, j, word, n + 1, check) ||
			   		DFS(board, i, j + 1, word, n + 1, check) ||
					DFS(board, i + 1, j, word, n + 1, check) ||
					DFS(board, i, j - 1, word, n + 1, check);
		check[i][j] = false;
		return found;
	}
};