class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 2));
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[arr[i]] = i;
        }
        for (int j = 2; j < n; j++) {
            for (int i = j - 1; i >= 0; i--) {
                if (m.find(arr[j] - arr[i]) != m.end() and m[arr[j] - arr[i]] < i) {
                    dp[i][j] = max(dp[i][j], dp[m[arr[j] - arr[i]]][i] + 1);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, dp[i][j]);
            }
        }

        return (ans == 2) ? 0 : ans;
    }
};