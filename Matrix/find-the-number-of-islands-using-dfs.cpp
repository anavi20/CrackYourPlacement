class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>&grid, int i, int j){
        if(i<0 || j<0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
        dfs(grid,i+1,j+1);
        dfs(grid,i-1,j-1);
        dfs(grid,i+1,j-1);
        dfs(grid,i-1,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0, n = grid.size(), m = grid[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return islands;
    }
};
