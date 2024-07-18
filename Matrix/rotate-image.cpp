// Time Complexity O(n*n) Space Complexity O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int i=0, j=n-1;

        while(i<j){
            for(int k=0; k<n; k++){
                swap(matrix[i][k], matrix[j][k]);
            }
            i++;
            j--;
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
