class Solution {
public:
    int helper(string s, int n, int dp[])
    {
        if (n == 0)
        {
            return 1;
        }

        if (s[s.size() - n] == '0')
        {
            return 0;
        }

        if (dp[n] > -1)
        {
            return dp[n];
        }

        int ans = helper(s.substr(1, n - 1), n - 1, dp);
        if (s.size() >= 2 && stoi(s.substr(0, 2)) <= 26)
        {
            ans += helper(s.substr(2, n - 2), n - 2, dp);
        }

        return dp[n] = ans;
    }


    int numDecodings(string s) {
        int n = s.size();
        int dp[n + 1];
        memset(dp, -1, sizeof(dp));
        return helper(s, n, dp);
    }
};