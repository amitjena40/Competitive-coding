//User function template for C++

class Solution {
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int, int> m;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (m[k - arr[i]] != 0)
            {
                ans += m[k - arr[i]];
            }

            m[arr[i]]++;
        }

        return ans;
    }
};