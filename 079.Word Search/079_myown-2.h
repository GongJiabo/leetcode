class Solution
{
private:
    int m, n;
    int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
    vector<vector<bool>> visited;

public:
    bool inArea(int x, int y)
    {
        return (x >= 0 && x < m&& y >= 0 && y < n);
    }
    
    bool searchWord(vector<vector<char>>& board, string& word, int index, int x, int y)
    {
        if (index == word.size()-1)
            return (word[index] == board[x][y]);
        else if(word[index]==board[x][y])
        {
            visited[x][y] = true;
            int newx, newy;
            for (int i = 0; i < 4; i++)
            {
                newx = x + dir[i][0];
                newy = y + dir[i][1];
                if (inArea(newx, newy) && !visited[newx][newy])
                    if (searchWord(board, word, index + 1, newx, newy))
                        return true;
            }
            visited[x][y] = false;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        m = board.size();
        assert(m > 0);
        n = board[0].size();
        //
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        //
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if(searchWord(board, word, 0, i, j))
                    return true;
        return false;
    }
};