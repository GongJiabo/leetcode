class Solution
{
private:
    vector<vector<string>> res;
    vector<bool> col;
    vector<bool> dia1;
    vector<bool> dia2;

public:
    void putQueens(int n, int index, vector<int>& row)
    {
        if (n == index) 
        {
            res.push_back(generateBoard(n, row));
            return;
        }
        else
        {
            //尝试将第index行的皇后，放在第i列
            for (int i = 0; i < n; i++)
            {
                if (!col[i] && !dia1[i + index] && !dia2[index - i + n - 1])
                {
                    row.push_back(i);
                    col[i] = true;
                    dia1[index + i] = true;
                    dia2[index - i + n - 1] = true;
                    //
                    putQueens(n, index + 1, row);
                    col[i] = false;
                    dia1[index + i] = false;
                    dia2[index - i + n - 1] = false;
                    row.pop_back();
                }
            }
        }
        return;
    }

    vector<string> generateBoard(int n, vector<int>& row)
    {
        assert(row.size() == n);
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; i++)
            board[i][row[i]] = 'Q';
        return board;
    }

    vector<vector<string>> solveNQueens(int n)
    {
        res.clear();
        if (n <= 0) return res;
        //
        vector<int> row;
        col = vector<bool>(n, false);
        dia1 = vector<bool>(2 * n - 1, false);
        dia2 = vector<bool>(2 * n - 1, false);
        //
        putQueens(n, 0, row);
        return res;
    }
};
