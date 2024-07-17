// Time Complexity:- O(nm)  Space Complexity:- O(nm)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int maxArea = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(dp[i - 1][j - 1] ,min(dp[i][j - 1],dp[i - 1][j])) + 1;
                    maxArea = max(maxArea, dp[i][j]);
                }
            }
        }

        return maxArea * maxArea;
    }
};

// Time Complexity:- O(nm)  Space Complexity:- O(2n)

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i][j-1] == '1') {
                    curr[j] = min(curr[j - 1], min(prev[j - 1], prev[j])) + 1;
                    maxArea = max(maxArea, curr[j]);
                }else{
                    curr[j] = 0;
                }
            }
            prev = curr;
        }

        return maxArea * maxArea;
    }
};
