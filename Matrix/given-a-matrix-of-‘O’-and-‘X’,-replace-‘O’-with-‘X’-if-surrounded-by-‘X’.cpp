// Time Complexity:- O(n*m) Space Complexity: O(n*m)

class Solution{
public:
    void dfs(int i, int j, vector<vector<char>>& mat){
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size()||mat[i][j] == 'X'|| mat[i][j]=='O'){return; }
        mat[i][j] = 'O';
        dfs(i+1,j,mat);
        dfs(i-1,j,mat);
        dfs(i,j+1,mat);
        dfs(i,j-1,mat);
        
        
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 'O'){
                    mat[i][j] = 'A';
                }
            }
        }
        
        for(int j=0; j<m; j++){
            if(mat[0][j] == 'A'){
                dfs(0,j,mat);
            }
        }
        
        for(int j=0; j<m; j++){
            if(mat[n-1][j] == 'A'){
                dfs(n-1,j,mat);
            }
        }
        
        for(int i=0; i<n; i++){
            if(mat[i][0] == 'A'){
                dfs(i,0,mat);
            }
        }
        
         for(int i=0; i<n; i++){
            if(mat[i][m-1] == 'A'){
                dfs(i,m-1,mat);
            }
        }
        
         for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 'A'){
                    mat[i][j] = 'X';
                }
            }
        }
        
        return mat;
        
    }
};
