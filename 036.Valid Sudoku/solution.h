bool isValidSudoku(vector<vector<char> > &board) {
        std::unordered_map<size_t, std::unordered_set<char>> row_map, col_map, cel_map;
        for (size_t i=0; i<board.size(); ++i)
            for (size_t j=0; j<board[0].size(); ++j) {
                if (board[i][j] == '.') continue;
				//直接判断能否插入stl模板即可
                if (!row_map[i].insert(board[i][j]).second) return false;
                if (!col_map[j].insert(board[i][j]).second) return false;
                if (!cel_map[i/3 * 10 + j/3].insert(board[i][j]).second) return false;
            }
        return true;
    }