class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())
        {
            return 0;
        }

        int n = matrix.size(), m = matrix[0].size();
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        int largest = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (matrix[i - 1][j - 1] == '1')
                {
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));

                    largest = max(largest, dp[i][j]);
                }
            }
        }

        return largest * largest;
    }
};