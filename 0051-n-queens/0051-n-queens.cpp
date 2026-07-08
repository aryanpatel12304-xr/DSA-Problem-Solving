class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<int> cols(n, 0), diag1(2*n, 0), diag2(2*n, 0);
        
        function<void(int)> backtrack = [&](int row) {
            if (row == n) {
                res.push_back(board);
                return;
            }
            for (int col = 0; col < n; col++) {
                if (cols[col] || diag1[row + col] || diag2[row - col + n]) continue;
                board[row][col] = 'Q';
                cols[col] = diag1[row + col] = diag2[row - col + n] = 1;
                
                backtrack(row + 1);
                
                board[row][col] = '.';
                cols[col] = diag1[row + col] = diag2[row - col + n] = 0;
            }
        };
        
        backtrack(0);
        return res;
    }
};
