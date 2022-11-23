class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<vector<char>> row(9, vector<char>(9, false));
        vector<vector<char>> col(9, vector<char>(9, false));
        vector<vector<char>> box(9, vector<char>(9, false));

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;
                int val = board[i][j] - '1';
                if(row[i][val] || col[j][val] || box[3*(i/3)+j/3][val]) return false;
                row[i][val] = col[j][val] = box[3*(i/3)+j/3][val] = true;
            }
        }
        
        return true;
    }
};