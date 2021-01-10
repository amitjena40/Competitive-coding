//User function template for C++

class Solution {
public:
    int celebrity(vector<vector<int> >& M, int n) {
        // code here

        int i = 0, j = n - 1;
        int celebrity = -1;

        while (i < j)
        {
            if (M[i][j] == 1)
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        celebrity = i;
        int indegree = 0, outdegree = 0;

        for (int c = 0; c < n; c++)
        {
            if (celebrity == c)continue;
            if (M[c][celebrity] == 1) indegree++;
            if (M[celebrity][c] == 1) outdegree++;
        }

        if (indegree == n - 1 && outdegree == 0)
        {
            return celebrity;
        }
        else
        {
            return -1;
        }
    }
};