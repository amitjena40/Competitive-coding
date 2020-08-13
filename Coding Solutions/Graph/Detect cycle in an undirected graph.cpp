/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/

bool isCyclicUtil(vector<int> g[], int V, int sv, bool visited[], int parent)
{
  visited[sv] = true;
  for (int x : g[sv])
  {
    if (x != parent && visited[x])
    {
      return true;
    }
    else if (!visited[x])
    {
      if (isCyclicUtil(g, V, x, visited, sv))
        return true;
    }
  }
  return false;
}

bool isCyclic(vector<int> g[], int V)
{
  // Your code here
  bool visited[V];
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < V; i++)
  {
    if (!visited[i] && isCyclicUtil(g, V, i, visited, -1))
      return true;
  }

  return false;
}