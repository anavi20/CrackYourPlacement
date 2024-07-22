class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>= grid.size() || j>= grid.size() || grid[i][j] == 2 || grid[i][j]==0){
            return;
        }

        grid[i][j] = 2;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }

    int bfs(int i, int j, vector<vector<int>>& grid){
        vector<int> x = {-1, 1, 0, 0};
        vector<int> y = {0, 0, -1, 1};
        int n = grid.size();
        queue<pair<int, int>> q;
        unordered_map<int, unordered_map<int, bool>> vis;
        int shortestDist = -1;
        q.push({i,j});
        vis[i][j] = true;


        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int, int> p = q.front();
                q.pop();
                int x_c = p.first, y_c = p.second;
                if(grid[x_c][y_c] == 1){
                    return shortestDist;
                }
                for(int i=0; i<4; i++){
                    int new_x = x_c + x[i], new_y = y_c + y[i];
                    if(new_x >=0 && new_y >=0 && new_x <n && new_y <n && grid[new_x][new_y] != 2){
                        if(!vis[new_x][new_y]){
                            vis[new_x][new_y] = true;
                            q.push({new_x, new_y});
                        }
                    }
                }

            }
            shortestDist++;

        }

        return INT_MAX;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), ans = INT_MAX;
        bool toBreak = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    dfs(i,j,grid);
                    toBreak = true;
                    break;
                }
            }
            if(toBreak){
                break;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    ans = min(ans, bfs(i,j,grid));
                }   
            }
        }
        return ans;
    }
};
