class Solution {
public:
    int mod = pow(10, 9) + 7;
    int DFS(int m, int n, int maxMove, int i, int j, vector<vector<vector<int>>> &dp, int currMove)
    {
        if (i < 0 || j < 0 || i >= m || j >= n)
        {
            return 1;
        }

        if (currMove == maxMove)
        {
            return 0;
        }

        if (dp[currMove][i][j] != -1)
        {
            return dp[currMove][i][j] % mod;
        }

        int ans = 0;
        ans = (ans + DFS(m, n, maxMove, i + 1, j, dp, currMove + 1)) % mod;
        ans = (ans + DFS(m, n, maxMove, i - 1, j, dp, currMove + 1)) % mod;
        ans = (ans + DFS(m, n, maxMove, i, j + 1, dp, currMove + 1)) % mod;
        ans = (ans + DFS(m, n, maxMove, i, j - 1, dp, currMove + 1)) % mod;
        dp[currMove][i][j] = ans;

        return dp[currMove][i][j] % mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>> (m + 1, vector<int> (n + 1, -1)));

        dp[maxMove][m][n] = DFS(m, n, maxMove, startRow, startColumn, dp, 0);
        return dp[maxMove][m][n];
    }
};