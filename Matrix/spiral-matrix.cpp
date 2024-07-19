class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n= matrix[0].size();
        int t = 0, b = m-1, l = 0, r = n-1;
        vector<int> spiralOrder;

        while(t<=b && l<=r){
            for(int i=l; i<=r; i++){
                spiralOrder.push_back(matrix[t][i]);
            }
            t++;

            for(int i=t; i<=b; i++){
                spiralOrder.push_back(matrix[i][r]);
            }
            r--;

            if(t<=b){
                for(int i=r; i>=l; i--){
                    spiralOrder.push_back(matrix[b][i]);
                }
                b--;
            }

            if(l<=r){
                for(int i=b; i>=t; i--){
                    spiralOrder.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return spiralOrder;
    }
};
