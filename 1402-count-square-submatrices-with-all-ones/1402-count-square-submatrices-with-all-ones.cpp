class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

        int n = matrix.size();    // number of rows
        int m = matrix[0].size(); // number of columns

        vector<vector<int>> dp(n, vector<int>(m, 0));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0];
            ans += dp[i][0];
        }
        for (int j = 1; j < m; j++) {
            dp[0][j] = matrix[0][j];
            ans += dp[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 1) {
                    dp[i][j] =
                        1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};