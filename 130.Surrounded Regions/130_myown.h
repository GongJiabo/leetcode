class Solution
{
private:
    int m, n;
    int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

public:
    bool inArea(int x, int y)
    {
        return (x >= 0 && x < m&& y >= 0 && y < n);
    }

    void dfs(vector<vector<char>>& board, int x, int y)
    {
        if(!inArea(x,y) || board[x][y]!='O') return; 
        board[x][y] = '1';
        int newx, newy;
        for (int i = 0; i < 4; i++)
        {
            newx = x + dir[i][0];
            newy = y + dir[i][1];
            dfs(board, newx, newy);
        }
        return;
    }

    void solve(vector<vector<char>>& board)
    {
        m = board.size();
        if (m <= 0) return;
        n = board[0].size();
        //首先从开始遍历为'0'的位置
        for (int i = 0; i < m; i++)
        {
            //第一列
            dfs(board, i, 0);
            //最后一列
            dfs(board, i, n - 1);
        }
        for (int j = 0; j < n; j++)
        {
            //第一行
            dfs(board, 0, j);
            //最后一行
            dfs(board, m - 1, j);
        }
        //从中间遍历
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '1') board[i][j] = 'O';
            }
        return;
    }
};