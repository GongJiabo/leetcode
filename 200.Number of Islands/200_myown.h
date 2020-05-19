class Solution
{
private:
    int m, n;
    int res;
    int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
    vector<vector<bool>> visited;

public:
    bool inArea(int x, int y)
    {
        return (x >= 0 && x < m&& y >= 0 && y < n);
    }

    void dfs(vector<vector<char>>& grid, int x, int y)
    {
        visited[x][y] = true;
        int newx, newy;
        for (int i = 0; i < 4; i++)
        {
            newx = x + dir[i][0];
            newy = y + dir[i][1];
            if (inArea(newx, newy) && !visited[newx][newy] && grid[newx][newy]=='1')
                dfs(grid, newx, newy);
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        m = grid.size();
        if (m <= 0) return 0;
        n = grid[0].size();
        //
        res = 0;
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i=0;i<m;i++)
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j]=='1')
                {
                    res++;
                    dfs(grid, i, j);
                }
            }
        return res;
    }
};