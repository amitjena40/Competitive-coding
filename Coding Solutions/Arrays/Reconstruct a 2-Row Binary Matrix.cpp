class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> ans(2, vector<int> (n, 0));
        int twosum = 0, onesum;
        for (int i = 0; i < n; i++) {
            if (colsum[i] == 2) {
                ans[0][i] = ans[1][i] = 1;
                twosum++;
            }
            else if (colsum[i] == 0) {
                ans[0][i] = ans[1][i] = 0;
            }
            else {
                onesum++;
            }
        }

        int lmt1 = upper - twosum, lmt2 = lower - twosum;
        if (lmt1 < 0 || lmt2 < 0 || lmt1 + lmt2 != onesum) {
            vector<vector<int>> ans2;
            return ans2;
        }


        for (int i = 0; i < n; i++) {
            if (colsum[i] == 1) {
                if (lmt1) {
                    ans[0][i] = 1;
                    lmt1--;
                }
                else {
                    ans[1][i] = 1;
                    lmt2--;
                }
            }
        }

        return ans;
    }
};