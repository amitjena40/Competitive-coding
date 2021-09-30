class Solution {
public:
    int find(int a, vector<int> &link)
    {
        if (a == link[a])
        {
            return a;
        }

        return link[a] = find(link[a], link);
    }

    void unite(int a, int b, vector<int> &link)
    {
        int p1 = find(a, link);
        int p2 = find(b, link);
        link[p2] = p1;
    }

    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int> link(n);

        for (int i = 0; i < n; i++)
        {
            link[i] = i;
        }

        for (int i = 0; i < n; i++)
        {
            unite(i, nums[i], link);
        }

        int ans = 1;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            int p = find(i, link);
            m[p]++;
            ans = max(ans, m[p]);
        }

        return ans;
    }
};