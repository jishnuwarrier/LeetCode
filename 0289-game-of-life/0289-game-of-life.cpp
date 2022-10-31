class Solution {
public:
   
    // In Place Algorithm
//     int m, n;
//     int change(vector<vector<int>>& board, int i, int j){
        
//         int count = 0;
//         for(int x=-1; x<=1; x++){
//             for(int y=-1; y<=1; y++){
//                 if(x==0 && y==0) continue;
//                 if(i+x>=0 && i+x<m && j+y>=0 && j+y<n && (board[i+x][j+y] == 1 || board[i+x][j+y] == 3))
//                     count++;
//             }
//         }  
//         if(board[i][j] == 0 && count == 3) return 2;
//         if(board[i][j] == 1 && (count<2 || count>3)) return 3;
//         return board[i][j];
//     }
    
//     void gameOfLife(vector<vector<int>>& board) {
        
//         m = board.size(), n = board[0].size();
        
//         for(int i=0; i<m; i++)
//             for(int j=0; j<n; j++)
//                 board[i][j] = change(board, i, j);
        
//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 if(board[i][j] == 2) board[i][j] = 1;
//                 if(board[i][j] == 3) board[i][j] = 0;
//             }
//         }
//     }
    
    void gameOfLife(vector<vector<int>>& board){
        
        int m=board.size(), n=board[0].size();
        vector<vector<int>>ans(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int count = 0;
                
                for(int x=-1; x<=1; x++){
                    for(int y=-1; y<=1; y++){
                        if(x==0 && y==0) continue;
                        int x1=i+x, y1=j+y;
                        if(x1<0 || x1==m || y1<0 || y1==n) continue;
                        if(board[x1][y1]==1) count++;
                    }
                }
                
                if(board[i][j]==1){
                    if(count==2 || count==3) ans[i][j]=1;
                    else ans[i][j]=0;
                }
                
                else{
                    if(count==3) ans[i][j]=1;
                    else ans[i][j]=0;
                }
            }
        } 
        
        
        board = ans;
    }
    
};