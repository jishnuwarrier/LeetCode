class Solution {
public:
    
    int m, n;
    int change(vector<vector<int>>& board, int i, int j){
        
        int count = 0;
        for(int x=-1; x<=1; x++){
            for(int y=-1; y<=1; y++){
                if(x==0 && y==0) continue;
                if(i+x>=0 && i+x<m && j+y>=0 && j+y<n && (board[i+x][j+y] == 1 || board[i+x][j+y] == 3))
                    count++;
            }
        }  
        if(board[i][j] == 0 && count == 3) return 2;
        if(board[i][j] == 1 && (count<2 || count>3)) return 3;
        return board[i][j];
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        
        m = board.size(), n = board[0].size();
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                board[i][j] = change(board, i, j);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 2) board[i][j] = 1;
                if(board[i][j] == 3) board[i][j] = 0;
            }
        }
    }
};