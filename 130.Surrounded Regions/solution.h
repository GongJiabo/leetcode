//from github->haoel
class Solution {
public:
    void solve(vector<vector<char> >& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();

        UnionFind uf(n*m+1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n-1 || j == 0 || j == m-1) { // side case, connect to dummy node
                    uf.connect(i*m + j, n*m);
                    continue;
                }
                char c = board[i][j]; // inner case, connect to same neighbor
                if (board[i+1][j] == c) uf.connect((i+1)*m + j, i*m + j);
                if (board[i-1][j] == c) uf.connect((i-1)*m + j, i*m + j);
                if (board[i][j+1] == c) uf.connect(i*m + (j+1), i*m + j);
                if (board[i][j-1] == c) uf.connect(i*m + (j-1), i*m + j);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !uf.connected(i*m + j, n*m)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};


//BFS
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return ;

        const int rowSize = board.size();
        const int colSize = board[0].size();
        const int xMovement[4] = {1, 0, -1, 0};
        const int yMovement[4] = {0, 1, 0, -1};

        queue<pair<int, int>> OsQueue;

        // 找边缘的O，然后对边缘的O进行BFS，相接的O替换为V
        for(int row = 0; row < rowSize; ++row) {
            for(int col = 0; col < colSize; ++col) {
                if(row > 0 && row < rowSize - 1 && col > 0 && col < colSize - 1) continue;

                if(board[row][col] == 'O') {
                    OsQueue.push({row, col});
                    board[row][col] = 'V';
                }
            }
        }
        // 这里是BFS
        while(!OsQueue.empty()) {
            int queueSize = OsQueue.size();
            //for(int i = 0; i < queueSize; ++i) 
            //{
                int curRow = OsQueue.front().first;
                int curCol = OsQueue.front().second; 
                OsQueue.pop();

                for(int k = 0; k < 4; ++k) {
                    const int nextRow = curRow + xMovement[k];
                    const int nextCol = curCol + yMovement[k];
                    if(nextRow < 0 || nextRow >= rowSize ||
                        nextCol < 0 || nextCol >= colSize) { continue; }

                    const char nextChar = board[nextRow][nextCol];
                    if(nextChar == 'O') {
                        board[nextRow][nextCol] = 'V';
                        OsQueue.push({nextRow, nextCol});
                    }
                }
           //}
        }

        // 边缘扩展剩下的O就是被包围的O， 然后把刚才写成V的O复原，就可以啦
        for(int row = 0; row < rowSize; ++row) {
            for(int col = 0; col < colSize; ++col) {
                if(board[row][col] == 'O') 
                    board[row][col] = 'X';
                else if(board[row][col] == 'V') 
                    board[row][col] = 'O';
            }
        }
    }
};
