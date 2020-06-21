class Solution
{
private:
    int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
    int m;
    int n;
    //vector<vector<bool>> visited;

public:
    bool inArea(int x, int y)
    {
        return (x >= 0 && x < m&& y >= 0 && y < n);
    }

    void dfs(vector<vector<int>>& matrix, int x, int y, int pre, vector<vector<bool>>& res)
    {
        if (!inArea(x, y) || matrix[x][y] < pre || res[x][y] ) return;
        res[x][y] = true;
        int newx, newy;
        for (int i = 0; i < 4; i++)
        {
            newx = x + dir[i][0];
            newy = y + dir[i][1];
            dfs(matrix, newx, newy, matrix[x][y], res);
        }
        
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix)
    {

        vector<vector<int>> res;
        res.clear();
        m = matrix.size();
        if (m <= 0) return res;
        n = matrix[0].size();
        //
        vector<vector<bool>> res1 = vector<vector<bool>>(m, vector<bool>(n, false));
        vector<vector<bool>> res2 = vector<vector<bool>>(m, vector<bool>(n, false));
       // vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));

        //从左边界和上边界遍历
        for (int i = 0; i < m; i++)
            dfs(matrix, i, 0, 0, res1);
        for (int j = 0; j < n; j++)
            dfs(matrix, 0, j, 0, res1);
        //从右边界和下边界
        for (int i = 0; i < m; i++)
            dfs(matrix, i, n - 1, 0, res2);
        for (int j = 0; j < n; j++)
            dfs(matrix, m - 1, j, 0, res2);
        //寻找相同的位置
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (res1[i][j] && res2[i][j])
                    res.push_back({ i,j });
            }
        return res;
    }
};