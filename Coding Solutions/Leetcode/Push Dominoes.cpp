class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> right(n, 0), left(n, 0);

        int count = 0;
        char prev = 'X';
        for (int i = 0; i < n; i++)
        {
            if (dominoes[i] == 'R')
            {
                count = 1;
                prev = 'R';
            }
            else if (dominoes[i] == 'L')
            {
                prev = 'L';
            }
            else if (prev == 'R')
            {
                right[i] = count++;
            }
        }

        count = 0;
        prev = 'X';
        for (int i = n - 1; i >= 0; i--)
        {
            if (dominoes[i] == 'L')
            {
                count = 1;
                prev = 'L';
            }
            else if (dominoes[i] == 'R')
            {
                prev = 'R';
            }
            else if (prev == 'L')
            {
                left[i] = count++;
            }
        }

        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (left[i] == 0 && right[i] == 0)
            {
                ans += dominoes[i];
            }
            else if (left[i] == 0)
            {
                ans += "R";
            }
            else if (right[i] == 0)
            {
                ans += "L";
            }
            else if (left[i] == right[i])
            {
                ans += ".";
            }
            else
            {
                ans += left[i] < right[i] ? "L" : "R";
            }
        }

        return ans;
    }
};