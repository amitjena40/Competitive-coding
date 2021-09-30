class Solution {
public:
    int longestMountain(vector<int>& A) {
        int i = 1;
        int n = A.size(), ans = 0;
        while (i < n) {
            int peak = 0, valley = 0;
            while (i < n && A[i] > A[i - 1]) {peak++; i++;}
            while (i < n && A[i] < A[i - 1]) {valley++; i++;}
            if (peak > 0 && valley > 0)ans = max(ans, peak + valley + 1);
            else if (!peak && !valley) i++;
        }
        return ans;
    }
};