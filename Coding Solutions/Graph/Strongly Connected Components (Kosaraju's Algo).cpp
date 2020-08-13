#include<bits/stdc++.h>

using namespace std;


/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/

void DFS1(vector<int> adj[], int sv, stack<int> &s, vector<int> &visited)
{
    visited[sv] = 1;
    for (auto it : adj[sv])
    {
        if (!visited[it])
        {
            DFS1(adj, it, s, visited);
        }
    }

    s.push(sv);
}

void DFS2(vector<int> adj[], int sv, vector<int> &visited)
{
    visited[sv] = 1;
    for (auto x : adj[sv])
    {
        if (!visited[x])
        {
            DFS2(adj, x, visited);
        }
    }
}

int kosaraju(int V, vector<int> adj[])
{
    // Your code here
    vector<int> adjT[V];
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }

    vector<int> visited(V, 0);
    stack<int> s;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            DFS1(adj, i, s, visited);
        }
    }

    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }

    int count = 0;
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        if (!visited[node])
        {
            count++;
            DFS2(adjT, node, visited);
        }
    }

    return count;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int m, n;
        vector<int> adj[a];
        for (int i = 0; i < b; i++) {
            cin >> m >> n;
            adj[m].push_back(n);
        }
        cout << kosaraju(a, adj) << endl;
    }
    return 0;
}
