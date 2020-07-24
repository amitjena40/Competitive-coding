/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/

void findislandsUtil(int x, int y, vector<int> A[], int N, int M, bool** visited)
{
    visited[x][y] = true;
    if (x >= 1)
    {
        if (A[x - 1][y] == 1 && !visited[x - 1][y])
        {
            findislandsUtil(x - 1, y, A, N, M, visited);
        }
    }

    if (x < N - 1)
    {
        if (A[x + 1][y] == 1 && !visited[x + 1][y])
        {
            findislandsUtil(x + 1, y, A, N, M, visited);
        }
    }

    if (y >= 1)
    {
        if (A[x][y - 1] == 1 && !visited[x][y - 1])
        {
            findislandsUtil(x, y - 1, A, N, M, visited);
        }
    }

    if (y < M - 1)
    {
        if (A[x][y + 1] == 1 && !visited[x][y + 1])
        {
            findislandsUtil(x, y + 1, A, N, M, visited);
        }
    }

    if (x >= 1 && y >= 1)
    {
        if (A[x - 1][y - 1] == 1 && !visited[x - 1][y - 1])
        {
            findislandsUtil(x - 1, y - 1, A, N, M, visited);
        }
    }

    if (x >= 1 && y < M - 1)
    {
        if (A[x - 1][y + 1] == 1 && !visited[x - 1][y + 1])
        {
            findislandsUtil(x - 1, y + 1, A, N, M, visited);
        }
    }

    if (x < N - 1 && y >= 1)
    {
        if (A[x + 1][y - 1] == 1 && !visited[x + 1][y - 1])
        {
            findislandsUtil(x + 1, y - 1, A, N, M, visited);
        }
    }

    if (x < N - 1 && y < M - 1)
    {
        if (A[x + 1][y + 1] == 1 && !visited[x + 1][y + 1])
        {
            findislandsUtil(x + 1, y + 1, A, N, M, visited);
        }
    }
}

int findIslands(vector<int> A[], int N, int M) {

    // Your code here
    int ans = 0;
    bool **visited = new bool*[N];
    for (int i = 0; i < N; i++)
    {
        visited[i] = new bool[M];
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (A[i][j] && !visited[i][j])
            {
                ans++;
                findislandsUtil(i, j, A, N, M, visited);
            }
        }
    }

    return ans;
}
