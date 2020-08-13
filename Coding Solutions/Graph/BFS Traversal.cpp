#include <iostream>
#include<queue>
using namespace std;

void print(int **edge, int V, int sv, bool *visited)
{
    visited[sv] = true;
    queue<int> q;
    q.push(sv);

    while (!q.empty())
    {
        sv = q.front();
        cout << sv << " ";
        q.pop();
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && edge[sv][i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
    int V, E;
    cin >> V >> E;
    int **edge = new int*[V];
    for (int i = 0; i < V; i++)
    {
        edge[i] = new int[V];
        for (int j = 0; j < V; j++)
            edge[i][j] = 0;
    }

    for (int i = 0; i < E; i++)
    {
        int f, s;
        cin >> f >> s;
        edge[f][s] = 1;
        edge[s][f] = 1;
    }

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    print(edge, V, 0, visited);
    return 0;
}
