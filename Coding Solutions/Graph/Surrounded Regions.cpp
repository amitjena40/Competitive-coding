class Solution {
public:
    void DFS(int x, int y, vector<vector<char>>& board, int n, int m)
    {
        board[x][y] = '1';
        if (x >= 1)
        {
            if (board[x - 1][y] == 'O')
            {
                DFS(x - 1, y, board, n, m);
            }
        }

        if (x <= n - 2)
        {
            if (board[x + 1][y] == 'O')
            {
                DFS(x + 1, y, board, n, m);
            }
        }

        if (y >= 1)
        {
            if (board[x][y - 1] == 'O')
            {
                DFS(x, y - 1, board, n, m);
            }
        }

        if (y <= m - 2)
        {
            if (board[x][y + 1] == 'O')
            {
                DFS(x, y + 1, board, n, m);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.size() == 0)
        {
            return;
        }

        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    if (board[i][j] == 'O')
                    {
                        DFS(i, j, board, n, m);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == '1')
                {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }

            }
        }
    }
};