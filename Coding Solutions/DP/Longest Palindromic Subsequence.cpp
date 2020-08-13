class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size()+1;
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        for(int i=0; i<n; i++)
        {
            dp[i][i] = 1;
        }
        
        for(int l=2; l<=n; l++)
        {
            for(int i=0; i<=n-l; i++)
            {
                int j = i+l-1;
                if(s[i]==s[j])
                {
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};
