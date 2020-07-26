// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX

int find(int i, int parent[])
{
    while (i != parent[i])
    {
        i = parent[i];
    }
    return i;
}

bool unionG(int x, int y, int parent[])
{
    int i = find(x, parent);
    int j = find(y, parent);

    if (i != j)
    {
        parent[j] = i;
        return true;
    }
    else
    {
        return false;
    }
}

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    return a.first < b.first;
}

int spanningTree(int V, int E, vector<vector<int>> &graph) {
    // code here
    int parent[V];
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    int ans = 0;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] < INT_MAX)
            {
                graph[j][i] = INT_MAX;
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] < INT_MAX)
            {
                edges.push_back(make_pair(graph[i][j], make_pair(i, j)));
            }
        }
    }

    sort(edges.begin(), edges.end(), cmp);
    for (auto it : edges)
    {
        if (unionG(it.second.first, it.second.second, parent))
        {
            ans += it.first;
        }
    }

    return ans;
}