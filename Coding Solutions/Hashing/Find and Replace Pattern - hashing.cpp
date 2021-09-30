class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;
        for (auto w : words) {
            m1.clear();
            m2.clear();
            int flag = 0;
            for (int i = 0; i < w.size(); i++) {
                if ((m1.find(pattern[i]) != m1.end() && m1[pattern[i]] != w[i]) || (m2.find(w[i]) != m2.end() && m2[w[i]] != pattern[i])) {
                    flag = 1;
                    break;
                }
                m1[pattern[i]] = w[i];
                m2[w[i]] = pattern[i];
            }
            if (flag == 0) {
                ans.push_back(w);
            }
        }

        return ans;
    }
};