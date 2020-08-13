class Solution {
public:
    string getPermutation(int n, int k) {
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[i + 1]++;
        }
        vector<string> ans;
        string possAns = "";
        fn(m, possAns, ans, k);
        return ans[k - 1];
    }

    void fn(map<int, int> m, string possAns, vector<string> &ans, int k)
    {
        if (possAns.size() == m.size())
        {
            ans.push_back(possAns);
            return;
        }

        if (ans.size() == k)
        {
            return;
        }

        for (auto it = m.begin(); it != m.end(); ++it)
        {
            if (it->second > 0)
            {
                possAns += to_string(it->first);
                it->second--;
                fn(m, possAns, ans, k);
                possAns.pop_back();
                it->second++;
            }
        }
    }
};