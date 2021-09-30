class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int j = 0, ans = 0, n = s.size(), maxf = 0;

        for (int i = 0; i < n; i++)
        {
            m[s[i]]++;
            maxf = max(maxf, m[s[i]]);

            while (i - j + 1 - maxf > k)
            {
                m[s[j]]--;
                j++;
            }

            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};