class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rowSize = board.size();
        int colSize = board[0].size();
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                if (board[i][j] == word[0]) {
                   if (dfs(board, word, 0, i, j, rowSize, colSize)) {
                       return true;
                   }
                }
            }
        }
        return false;
        
    }

    bool dfs(vector<vector<char>>& board, string word, int index, int row, int col, int rowSize, int colSize) {
        if (row >= rowSize || col >= colSize ||row < 0 ||col < 0|| board[row][col] != word[index]) {
            return false;
        }

        if (index == word.size() - 1) {
            return true;
        }

        board[row][col] = '#';

        if (dfs(board, word, index + 1, row + 1, col, rowSize, colSize) ||
            dfs(board, word, index + 1, row, col + 1, rowSize, colSize) ||
            dfs(board, word, index + 1, row - 1, col, rowSize, colSize) ||
            dfs(board, word, index + 1, row, col - 1, rowSize, colSize)) {
                return true;
            }
        board[row][col] = word[index];

        return false;
    }
};