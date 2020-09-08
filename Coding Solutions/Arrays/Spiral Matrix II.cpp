class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int item = 1, dir = 0;
        vector<vector<int>> ans(n, vector<int>(n));
        int top = 0, down = n - 1, left = 0, right = n - 1;
        while (item <= n * n)
        {
            if (dir == 0)
            {
                for (int i = left; i <= right; i++)
                {
                    ans[top][i] = item++;
                }
                top++;
            }
            else if (dir == 1)
            {
                for (int i = top; i <= down; i++)
                {
                    ans[i][right] = item++;
                }
                right--;
            }
            else if (dir == 2)
            {
                for (int i = right; i >= left; i--)
                {
                    ans[down][i] = item++;
                }
                down--;
            }
            else
            {
                for (int i = down; i >= top; i--)
                {
                    ans[i][left] = item++;
                }
                left++;
            }

            dir = (dir + 1) % 4;
        }

        return ans;
    }
};