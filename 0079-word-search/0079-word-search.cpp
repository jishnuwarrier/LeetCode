class Solution {
public:
    vector<vector<bool>> visited;
    int m, n;
    
    bool dfs(vector<vector<char>>& board, string word, int pos, int i, int j){
        
        if(pos == word.size())
            return true;
        
        if(i<0 || j<0 || i==m || j==n || word[pos] != board[i][j] || visited[i][j] == true)
            return false;
 
        visited[i][j] = true;
        bool ret =  (dfs(board, word, pos+1, i+1, j) || dfs(board, word, pos+1, i-1, j) || dfs(board, word, pos+1, i, j-1) || dfs(board, word, pos+1, i, j+1));
        visited[i][j] = false;
        
        return ret;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        m = board.size(), n = board[0].size(); 
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        
        bool ans = false;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(word[0] == board[i][j])
                   ans = ans || dfs(board, word, 0, i, j);
            }
        }
        
        return ans;
    }
};