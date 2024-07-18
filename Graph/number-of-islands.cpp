class Solution {
public:

    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()|| grid[i][j] == '0' || grid[i][j] == 'A'){
            return;
        }
        grid[i][j] = 'A';
        dfs(grid, i+1,j);
        dfs(grid, i-1,j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n =grid[0].size(),numberOfIslands=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    numberOfIslands++;
                    dfs(grid,i,j);
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 'A'){
                    grid[i][j] == 'O';
                }
            }
        }
        return numberOfIslands;
    }
};
