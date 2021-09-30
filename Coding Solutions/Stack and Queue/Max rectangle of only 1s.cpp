int maxRect(int a[], int n)
{
    stack<int> s;
    int ans = 0;
    s.push(0);

    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && a[i] < a[s.top()])
        {
            int ht = s.top();
            s.pop();

            if (s.empty())
            {
                ans = max(ans, a[ht] * i);
            }
            else
            {
                ans = max(ans, a[ht] * (i - s.top() - 1));
            }
        }

        s.push(i);
    }

    while (!s.empty())
    {
        int ht = s.top();
        s.pop();

        if (s.empty())
        {
            ans = max(ans, a[ht] * n);
        }
        else
        {
            ans = max(ans, a[ht] * (n - s.top() - 1));
        }
    }

    return ans;
}

int maxArea(int M[MAX][MAX], int n, int m) {
    // Your code here

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] != 0)
                    M[i][j] += M[i - 1][j];
            }
        }

        ans = max(ans, maxRect(M[i], m));
    }

    return ans;
}