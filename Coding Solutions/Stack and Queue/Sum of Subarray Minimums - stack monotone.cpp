class Solution {
public:
#define mod 1000000007
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<pair<int, int>> s1;
        vector<int> left(n);

        left[0] = 1;
        s1.push({arr[0], 1});
        for (int i = 1; i < n; i++) {
            int f = arr[i], s = 1;
            while (!s1.empty() && s1.top().first >= f) {
                s += s1.top().second;
                s1.pop();
            }
            left[i] = s;
            s1.push({f, s});
        }

        stack<pair<int, int>> s2;
        vector<int> right(n);

        right[n - 1] = 1;
        s2.push({arr[n - 1], 1});
        for (int i = n - 2; i >= 0; i--) {
            int f = arr[i], s = 1;
            while (!s2.empty() && s2.top().first > f) {
                s += s2.top().second;
                s2.pop();
            }
            right[i] = s;
            s2.push({f, s});
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + (long)arr[i] * left[i] * right[i]) % mod;
        }

        return ans;
    }
};