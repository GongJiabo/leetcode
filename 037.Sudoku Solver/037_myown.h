class Solution {
public:
void solveSudoku(vector<vector<char>>& board)
{
	solvesudokuDFS(board, 0, 0);
}

bool solvesudokuDFS(vector<vector<char> >&board, int i, int j)
{
	if (i == 9) return true;								//每行填写，填完最后一行退出
	if (j >= 9) return solvesudokuDFS(board, i + 1, 0);		//填到每行最后一列，跳到下一行
	if (board[i][j] == '.')									//找到没有填数据的位置
	{
		for (int k = 1; k <= 9; ++k)
		{
			board[i][j] = (char)k + '0';
			if (isvalid(board, i, j))						//依次填写数据并判断是否可行
			{
				if (solvesudokuDFS(board, i, j + 1)) return true;		//可行，继续填写下一列
			}
			board[i][j] = '.';
		}
	}														//若有数据，填写该位置下一个位置
	else
	{
		return solvesudokuDFS(board, i, j + 1);
	}
	return false;
}


bool isvalid(vector<vector<char>> &board, int i, int j)
{
	for (int col = 0; col<9; ++col)
	{
		if (col != j&&board[i][j] == board[i][col]) return false;
	}
	for (int row = 0; row<9; ++row)
	{
		if (row != i&&board[i][j] == board[row][j]) return false;
	}
	for (int l = i / 3 * 3; l<i / 3 * 3 + 3; ++l)
		for (int m = j / 3 * 3; m<j / 3 * 3 + 3; ++m)
		{
			if (l != i&&m != j&&board[i][j] == board[l][m]) return false;
		}
	return true;
}

 
};