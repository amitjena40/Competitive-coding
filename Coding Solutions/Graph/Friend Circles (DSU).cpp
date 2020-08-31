class Solution {
public:
    int find(int x, int link[])
    {
        if (x == link[x])
            return x;

        return link[x] = find(link[x], link);
    }

    bool same(int a, int b, int link[])
    {
        return find(a, link) == find(b, link);
    }

    void unite(int a, int b, int link[])
    {
        a = find(a, link);
        b = find(b, link);
        link[b] = a;
    }


    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        int link[n];
        for (int i = 0; i < n; i++)
        {
            link[i] = i;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < M[i].size(); j++)
            {
                if (M[i][j] == 1)
                {
                    unite(i, j, link);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i == link[i])
                ans++;
        }
        return ans;
    }
};