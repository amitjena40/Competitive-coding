class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> m;
        int j = 0, ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
            while (m['a'] >= 1 && m['b'] >= 1 && m['c'] >= 1)
            {
                m[s[j]]--;
                j++;
            }
            ans += j;
        }

        return ans;
    }
};