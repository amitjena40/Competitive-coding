class Solution {
public:
    double func(int n, int k, int i, int j, vector<vector<vector<double>>> &dp)
    {
        if (i < 0 || j < 0 || i >= n || j >= n)
        {
            return 0;
        }

        if (k == 0)
        {
            return 1;
        }

        if (dp[k][i][j] != -1)
        {
            return dp[k][i][j];
        }

        vector<pair<int, int>> dir = {{ -1, -2}, { -2, -1}, { -2, 1}, { -1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};

        double prob = 0;
        for (auto x : dir)
        {
            prob += 0.125 * func(n, k - 1, i + x.first, j + x.second, dp);
        }

        dp[k][i][j] = prob;
        return prob;
    }

    double knightProbability(int n, int k, int row, int column) {

        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>> (n + 1, vector<double>(n + 1, -1.0)));
        dp[k][n][n] = func(n, k, row, column, dp);
        return dp[k][n][n];
    }
};