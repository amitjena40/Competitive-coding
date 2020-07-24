bool BFS(int G[][MAX], int V, int sv, int color[])
{
    color[sv] = 1;
    queue<int> q;
    q.push(sv);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < V; i++)
        {
            if (G[node][i] == 1 && color[i] == 0)
            {
                color[i] = 3 - color[node];
                q.push(i);
            }

            if (G[node][i] == 1 && color[i] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int G[][MAX], int V)
{
    //Your code here
    if (V == 0)
    {
        return true;
    }

    int color[V];
    memset(color, 0, sizeof(color));
    for (int i = 0; i < V; i++)
    {
        if (color[i] == 0)
        {
            if (!BFS(G, V, i, color))
            {
                return false;
            }
        }
    }

    return true;
}