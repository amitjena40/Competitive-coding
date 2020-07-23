/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

bool DFS(vector<int> adj[], int sv, bool* white, bool* grey, bool* black)
{
    white[sv] = false;
    grey[sv] = true;

    for (int x : adj[sv])
    {
        if (black[x])
        {
            continue;
        }

        if (grey[x])
        {
            return true;
        }

        if (DFS(adj, x, white, grey, black))
        {
            return true;
        }
    }

    grey[sv] = false;
    black[sv] = true;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    bool *white = new bool[V];
    bool *grey = new bool[V]();
    bool *black = new bool[V]();

    memset(white, true, sizeof(white));
    for (int i = 0; i < V; i++)
    {
        if (!black[i])
        {
            if (DFS(adj, i, white, grey, black))
            {
                return true;
            }
        }
    }

    return false;
}