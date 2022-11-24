class Solution {
public:
    int m, n;
    
    bool dfs(vector<vector<char>>& board, string word, int pos, int i, int j){
        
        if(pos == word.size())
            return true;
        
        if(i<0 || j<0 || i==m || j==n || word[pos] != board[i][j] || board[i][j] == '0')
            return false;
 
        board[i][j] = '0';
        bool ret =  (dfs(board, word, pos+1, i+1, j) || dfs(board, word, pos+1, i-1, j) || dfs(board, word, pos+1, i, j-1) || dfs(board, word, pos+1, i, j+1));
        
        board[i][j] = word[pos];
        return ret;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        m = board.size(), n = board[0].size();         
        bool ans = false;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(word[0] == board[i][j])
                   ans = ans || dfs(board, word, 0, i, j);
                
                if(ans) return ans;
            }
        }
        
        return false;
    }
};