class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int f(int i, int j, int m, int n, vector<vector<int>>& grid,vector<vector<int>>&dp) {
        if (i == m - 1 && j == n - 1) {
            return 1; // Reached the destination.
        }

        int count = 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if (isValid(i + 1, j, m, n)) {
            count += f(i + 1, j, m, n, grid,dp);
        }
        if (isValid(i, j + 1, m, n)) {
            count += f(i, j + 1, m, n, grid,dp);
        }

        return dp[i][j]=count;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(0, 0, m, n, grid,dp);
    }
};
