class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> m;
        int countmax = 0;
        char maxchar;
        for (auto x : s) {
            m[x]++;
            if (m[x] > countmax) {
                countmax = m[x];
                maxchar = x;
            }
        }

        int n = s.size();
        if (countmax > (n + 1) / 2) {
            return "";
        }

        int idx = 0;
        string ans = s;
        while (m[maxchar]) {
            ans[idx] = maxchar;
            m[maxchar]--;
            idx += 2;
        }

        for (int i = 0; i < n; i++) {
            while (m[s[i]]) {
                if (idx >= n) {
                    idx = 1;
                }
                ans[idx] = s[i];
                idx += 2;
                m[s[i]]--;
            }
        }

        return ans;
    }
};