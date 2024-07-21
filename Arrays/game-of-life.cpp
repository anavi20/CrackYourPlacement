class Solution {
public:
    int solve(vector<vector<int>>& board, int x_c, int y_c) {
        int m = board.size(), n = board[0].size(), neighbour = 0, ans=board[x_c][y_c];
        vector<int> x = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> y = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < 8; i++) {
                int new_x = x_c + x[i];
                int new_y = y_c + y[i];
                if (new_x >= 0 && new_y >= 0 && new_x < m && new_y < n &&
                    (board[new_x][new_y] == 1 || board[new_x][new_y] == -1)) {
                    neighbour++;
                }
        }
        if(board[x_c][y_c] == 1){
            if(neighbour<2 || neighbour > 3){
                ans = -1;
            }
        }else{
            if(neighbour == 3){
                ans = 2;
            }
        }
        return ans;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = solve(board, i, j);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(board[i][j] == -1){
                    board[i][j] = 0;
                }
                if(board[i][j] == 2){
                    board[i][j] = 1;
                }
            }
        }
    }
};
