class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int currCost = 0;
        int j = 0, n = s.size(), ans = 0;

        for (int i = 0; i < n; i++)
        {
            currCost += abs(s[i] - t[i]);
            while (currCost > maxCost)
            {
                currCost -= abs(s[j] - t[j]);
                j++;
            }
            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};