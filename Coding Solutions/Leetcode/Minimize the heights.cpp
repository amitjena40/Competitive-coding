class Solution {
public:
    int getMinDiff(int arr[], int n, int k) {
        // code here

        if (n == 1)
        {
            return 0;
        }

        sort(arr, arr + n);

        int ans = arr[n - 1] - arr[0];
        int small = arr[0] + k;
        int large = arr[n - 1] - k;

        if (small > large)
        {
            swap(small, large);
        }

        for (int i = 1; i < n - 1; i++)
        {
            int x = arr[i];
            int add = x + k, sub = x - k;

            if (sub >= small || add <= large)
            {
                continue;
            }

            if (large - sub <= add - small)
            {
                small = sub;
            }
            else
            {
                large = add;
            }
        }

        return min(ans, large - small);
    }
};