class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
        {
            return 0;
        }

        vector<int> left(n), right(n);
        int Lmin = prices[0], Rmax = prices[n - 1];

        left[0] = right[n - 1] = 0;

        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], prices[i] - Lmin);
            Lmin = min(Lmin, prices[i]);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1], Rmax - prices[i]);
            Rmax = max(Rmax, prices[i]);
        }

        int profit = right[0];
        for (int i = 1; i < n; i++)
        {
            profit = max(profit, left[i - 1] + right[i]);
        }

        return profit;
    }
};