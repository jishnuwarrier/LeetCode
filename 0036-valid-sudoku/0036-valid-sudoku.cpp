class Solution {
public:
    
    bool checkrow(vector<vector<char>>& board, int row){
        
        set<int> s;
        for(int j=0; j<9; j++){
            if(board[row][j] == '.') continue;
            if(s.find(board[row][j]) == s.end()) s.insert(board[row][j]);
            else return false;
        }
        return true;
    }
    
    bool checkcol(vector<vector<char>>& board, int col){
        
        set<int> s;
        for(int i=0; i<9; i++){
            if(board[i][col] == '.') continue;
            if(s.find(board[i][col]) == s.end()) s.insert(board[i][col]);
            else return false;
        }
        return true;
    }
    
    bool checkbox(vector<vector<char>>& board, int box){
        
        set<int> s;
        int x = 3*(box/3), y = 3*(box%3);
        
        for(int a=0; a<9; a++){
            int i = x+a/3, j=y+a%3;
            if(board[i][j] == '.') continue;
            if(s.find(board[i][j]) == s.end()) s.insert(board[i][j]); 
            else return false;    
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        bool ans = true;
        
        for(int i=0; i<9; i++){
            if(ans == false) return false;
            ans = ans & checkrow(board, i) & checkcol(board, i) & checkbox(board, i);
        }
        
        return ans;
    }
};