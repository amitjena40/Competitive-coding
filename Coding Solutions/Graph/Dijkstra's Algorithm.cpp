
#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(vector<vector<int>> , int , int );

int printSolution(vector <int> dist, int n)
{

    for (int i = 0; i < n; i++)
        printf("%d ", dist[i]);

}
int main()
{
    int t;
    int V;
    cin >> t;
    while (t--) {
        cin >> V;

        vector<vector<int>> g(V);

        for (int i = 0; i < V; i++) {
            vector<int> temp(V);
            g[i] = temp;
        }

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cin >> g[i][j];
            }
        }

        int s;
        cin >> s;

        vector <int> res = dijkstra(g, s, V);
        printSolution (res, V);
        cout << endl;
    }
    return 0;
}

/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    // Your code here
    vector<int> distance(V);
    for (int i = 0; i < V; i++)
    {
        distance[i] = INT_MAX;
    }

    distance[src] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, src});
    bool visited[V];
    memset(visited, false, sizeof(visited));
    while (!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if (!visited[x])
        {
            visited[x] = true;
            for (int i = 0; i < V; i++)
            {
                if (g[x][i] != 0)
                {
                    if (distance[x] + g[x][i] < distance[i])
                    {
                        distance[i] = distance[x] + g[x][i];
                        q.push({ -distance[i], i});
                    }
                }
            }
        }
    }
    return distance;
}