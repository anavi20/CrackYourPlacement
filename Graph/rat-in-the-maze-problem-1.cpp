class Solution {
  public:
    void dfs(int i, int j,string&path, vector<vector<int>>& mat, vector<vector<bool>>& vis,  vector<string>& ans)
    {
        int n = mat.size();
        if(mat[i][j] == 0 || vis[i][j] == true)
        {
            return;
        }
        if(i==n-1 && j==n-1){
           ans.push_back(path);
           return;
        }
        vis[i][j] = true;
        if(i-1 >= 0){
            path.push_back('U');
            dfs(i-1,j,path,mat,vis,ans);
            path.pop_back();
        }
        
        if(i+1 < n){
            path.push_back('D');
            dfs(i+1,j,path,mat,vis,ans);
            path.pop_back();
        }
        
        if(j-1 >=0){
            path.push_back('L');
            dfs(i, j-1,path,mat,vis,ans);
            path.pop_back();
        }
        
        if(j+1 < n){
            path.push_back('R');
            dfs(i,j+1,path,mat,vis,ans);
            path.pop_back();
        }
        
        vis[i][j] = false;
        
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        if(mat[0][0] == 0){
            return {};
        }
        int n = mat.size();
        vector<vector<bool>> visited(n, vector<bool>(n,false));
        vector<string> ans;
        string path="";
        dfs(0,0,path,mat,visited,ans);
        return ans;
        
    }
};
