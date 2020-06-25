class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i = 0, j = 0, max_len = 0;
        while (i < A.size())
        {
            if (A[i] == 0)
            {
                K--;
            }

            while (K < 0)
            {
                if (A[j] == 0)
                {
                    K++;
                }
                j++;
            }

            max_len = max(max_len, i - j + 1);
            i++;
        }

        return max_len;
    }
};