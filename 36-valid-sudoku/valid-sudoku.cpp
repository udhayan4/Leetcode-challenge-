class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int k = sqrt(n);
        
        vector<vector<bool>> row(n, vector<bool>(n, false));
        vector<vector<bool>> col(n, vector<bool>(n, false));
        vector<vector<bool>> box(n, vector<bool>(n, false));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') continue;
                
                int num = board[i][j] - '1'; 
                int box_idx = (i / k) * k + (j / k); 
                
                if (row[i][num] || col[j][num] || box[box_idx][num]) return false;
                
                row[i][num] = col[j][num] = box[box_idx][num] = true;
            }
        }
        return true;

    }
};