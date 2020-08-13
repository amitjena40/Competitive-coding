class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_zero = false;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int j = 0; j < m; j++)
        {
            if (matrix[0][j] == 0)
            {
                first_zero = true;
                break;
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < n; i++)
        {
            bool row_zero = false;
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row_zero = true;
                    break;
                }
            }

            for (int j = 0; j < m; j++)
            {
                if (matrix[0][j] == 0 || row_zero)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (first_zero)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[0][j] = 0;
            }
        }
    }
};