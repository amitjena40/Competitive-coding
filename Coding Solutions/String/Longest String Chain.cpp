class Solution {
public:
    static bool cmp(string s1, string s2)
    {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        unordered_map<string, int> dp;

        int ans = 0;
        for (string w : words)
        {
            int n = w.size();
            for (int i = 0; i < n; i++)
            {
                string prev = w.substr(0, i) + w.substr(i + 1);
                dp[w] = max(dp[w], (dp.find(prev) == dp.end() ? 1 : 1 + dp[prev]));
            }

            ans = max(ans, dp[w]);
        }

        return ans;
    }
};