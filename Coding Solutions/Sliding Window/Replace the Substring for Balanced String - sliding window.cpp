class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> m;
        for (char ch : s)
        {
            m[ch]++;
        }

        int n = s.size();
        int k = n / 4, ans = INT_MAX;

        int j = 0;
        for (int i = 0; i < n; i++)
        {
            m[s[i]]--;
            while (j < n && m['Q'] <= k && m['W'] <= k && m['E'] <= k && m['R'] <= k)
            {
                ans = min(ans, i - j + 1);
                m[s[j]]++;
                j++;
            }
        }

        return ans;
    }
};