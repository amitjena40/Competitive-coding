class Solution {
public:
    void dfs1(int v, vector<vector<int>> &G, vector<int> &distance, vector<int> &count, int p = -1)
    {
        for (auto x : G[v])
        {
            if (x == p)continue;
            dfs1(x, G, distance, count, v);
            count[v] += count[x];
            distance[v] += distance[x] + count[x];
        }
        count[v] += 1;
    }

    void dfs2(int v, vector<vector<int>> &G, vector<int> &distance, vector<int> &count, int p = -1)
    {
        for (auto x : G[v])
        {
            if (x == p)continue;
            distance[x] = distance[v] - count[x] + G.size() - count[x];
            dfs2(x, G, distance, count, v);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> G(n);
        for (auto x : edges)
        {
            G[x[0]].push_back(x[1]);
            G[x[1]].push_back(x[0]);
        }

        vector<int> distance(n, 0);
        vector<int> count(n, 0);

        dfs1(0, G, distance, count);
        dfs2(0, G, distance, count);
        return distance;
    }
};