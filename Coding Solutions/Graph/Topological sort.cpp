// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/

void topoSortUtil(int V, vector<int> adj[], int sv, bool* visited, stack<int> &s)
{
    visited[sv] = true;
    for (int x : adj[sv])
    {
        if (!visited[x])
        {
            topoSortUtil(V, adj, x, visited, s);
        }
    }

    s.push(sv);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    stack<int> s;
    bool *visited = new bool[V]();
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            topoSortUtil(V, adj, i, visited, s);
        }
    }

    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}