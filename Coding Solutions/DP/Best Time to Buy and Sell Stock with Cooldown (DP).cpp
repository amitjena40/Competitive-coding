class Solution {
public:
    int util(vector<int> &prices, int curr, int n, int dp[])
    {
        if (curr >= n)
        {
            return 0;
        }

        if (dp[curr] != -1)
        {
            return dp[curr];
        }

        dp[curr] = 0;
        for (int i = curr + 1; i < n; i++)
        {
            if (prices[i] > prices[curr])
            {
                dp[curr] = max(dp[curr], prices[i] - prices[curr] + util(prices, i + 2, n, dp));
            }
        }

        dp[curr] = max(dp[curr], util(prices, curr + 1, n, dp));
        return dp[curr];
    }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n + 1];
        memset(dp, -1, sizeof(dp));
        return util(prices, 0, n, dp);
    }
};