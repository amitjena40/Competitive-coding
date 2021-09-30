class Solution {
public:
    int DFS(int i, int j, int row, int col, vector<vector<int>>& dp, vector<vector<int>>& matrix) {
        if (dp[i][j] > 0)
        {
            return dp[i][j];
        }

        int res = 1;
        if (i + 1 < row && matrix[i + 1][j] > matrix[i][j])
        {
            res = max(res, 1 + DFS(i + 1, j, row, col, dp, matrix));
        }

        if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j])
        {
            res = max(res, 1 + DFS(i - 1, j, row, col, dp, matrix));
        }

        if (j + 1 < col && matrix[i][j + 1] > matrix[i][j])
        {
            res = max(res, 1 + DFS(i, j + 1, row, col, dp, matrix));
        }

        if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j])
        {
            res = max(res, 1 + DFS(i, j - 1, row, col, dp, matrix));
        }

        dp[i][j] = res;
        return res;
    }


    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0)
        {
            return 0;
        }
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector(m, 0));

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = max(ans, DFS(i, j, n, m, dp, matrix));
            }
        }

        return ans;
    }
};