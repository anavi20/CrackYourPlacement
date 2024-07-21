class Solution {
public:
    bool solve(int i, int j, vector<vector<char>>& board, 
    vector<vector<bool>>& vis, int idx, string word){
        if(idx == word.length()-1){
            return true;
        }
        vis[i][j] = true;
        int m = board.size();
        int n = board[0].size();
        if(i-1>=0 && !vis[i-1][j] && board[i-1][j] == word[idx+1] && solve(i-1,j,board,vis,idx+1,word)){
            return true;
        }
        if(i+1<m && !vis[i+1][j] && board[i+1][j] == word[idx+1] && solve(i+1,j,board,vis,idx+1,word)){
            return true;
        }
        if(j-1>=0 && !vis[i][j-1] && board[i][j-1] == word[idx+1] && solve(i,j-1,board,vis,idx+1,word)){
            return true;
        }
        if(j+1<n && !vis[i][j+1] && board[i][j+1] == word[idx+1] && solve(i,j+1,board,vis,idx+1,word)){
            return true;
        }
        
        vis[i][j] = false;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visted(m,vector<bool>(n,false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] ==  word[0] && solve(i,j,board,visted,0,word)){
                    return true;
                }
            }
        }

        return false;
    }
};
