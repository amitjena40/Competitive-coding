// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX
int spanningTree(int V, int E, vector<vector<int>> &graph) {
    // code here
    priority_queue<pair<int, int>> pq;
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    int src = 0;
    key[src] = 0;
    pq.push({0, src});

    int ans = 0;
    while (!pq.empty())
    {
        int x = pq.top().second;
        pq.pop();
        if (inMST[x])
        {
            continue;
        }
        inMST[x] = true;
        ans += key[x];
        for (int i = 0; i < V; i++)
        {
            if (!inMST[i] && key[i] > graph[x][i])
            {
                key[i] = graph[x][i];
                pq.push(make_pair(-key[i], i));
            }
        }
    }

    return ans;
}