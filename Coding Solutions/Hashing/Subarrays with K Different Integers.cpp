class Solution {
public:
    int subarraysWithAtmostKDistinct(vector<int>& a, int K)
    {
        int ans = 0;
        unordered_map<int, int> m;
        int i = 0, j = 0, n = a.size();
        while (i < n)
        {
            if (m.find(a[i]) == m.end())
            {
                m[a[i]] = 0;
            }

            m[a[i]]++;

            while (m.size() > K)
            {
                m[a[j]]--;
                if (m[a[j]] == 0)
                {
                    m.erase(a[j]);
                }

                j++;
            }

            ans += i - j + 1;
            i++;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& a, int K) {
        return subarraysWithAtmostKDistinct(a, K) - subarraysWithAtmostKDistinct(a, K - 1);
    }
};