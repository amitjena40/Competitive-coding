// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/

void dfsUtil(vector<int> g[], int N, int sv, bool *visited, vector<int> &ans)
{
    ans.push_back(sv);
    visited[sv] = true;
    for (int i = 0; i < g[sv].size(); i++)
    {
        if (!visited[g[sv][i]])
        {
            dfsUtil(g, N, g[sv][i], visited, ans);
        }
    }
}

vector <int> dfs(vector<int> g[], int N)
{

    // Your code here
    vector<int> ans;
    bool *visited = new bool[N]();
    dfsUtil(g, N, 0, visited, ans);
    return ans;

}

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {

        int N, E;
        cin >> N >> E;

        vector<int> g[N];
        bool vis[N];

        memset(vis, false, sizeof(vis));

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout << endl;

    }
}  // } Driver Code Ends