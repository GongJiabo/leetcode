class Solution {
public:
bool isValidSudoku(vector<vector<char>>& board)
{
	//line
	bool bline = true;
	for (int i = 0; i < 9; i++)
		bline = bline&isValid_9box(board[i]);
	//column
	bool bcolu = true;
	for (int i = 0; i < 9; i++)
	{
		vector<char> Vcolumn;
		for (int j = 0; j < 9; j++)
		{
			Vcolumn.push_back(board[j][i]);
		}
		bcolu = bcolu&isValid_9box(Vcolumn);
	}
	//9boxes
	bool b9box = true;
	for (int i = 0; i < 9; i += 3)
	{
	
		for (int j = 0; j < 9; j += 3)
		{
			vector<char> Vboxes;
			Vboxes.push_back(board[i][j]);
			Vboxes.push_back(board[i][j + 1]);
			Vboxes.push_back(board[i][j + 2]);
			Vboxes.push_back(board[i + 1][j]);
			Vboxes.push_back(board[i + 1][j + 1]);
			Vboxes.push_back(board[i + 1][j + 2]);
			Vboxes.push_back(board[i + 2][j]);
			Vboxes.push_back(board[i + 2][j + 1]);
			Vboxes.push_back(board[i + 2][j + 2]);
			b9box = b9box&isValid_9box(Vboxes);
		}
	
	}
	return b9box&bcolu&bline;
}

bool isValid_9box(vector<char> &line)
{
	for (decltype(line.size()) i = 0; i < line.size() - 1; i++)
	{
		for (decltype(i) j = i + 1; j < line.size(); j++)
		{
			if (line[i] != '.' && line[i] == line[j]) return false;
		}
	}
	return true;
}

};