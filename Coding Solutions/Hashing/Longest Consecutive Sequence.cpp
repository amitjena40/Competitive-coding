class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto x : nums)
        {
            s.insert(x);
        }

        if (s.empty())
        {
            return 0;
        }

        int ans = 1;
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            if (s.find(*it - 1) == s.end())
            {
                int num = *it, len = 1;
                while (s.find(num + 1) != s.end())
                {
                    num++;
                    len++;
                }

                ans = max(ans, len);
            }
        }

        return ans;
    }
};