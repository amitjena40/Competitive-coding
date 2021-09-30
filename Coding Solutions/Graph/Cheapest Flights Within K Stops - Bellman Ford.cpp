class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> currDistance(n, INT_MAX);
        vector<int> tempDistance(n, INT_MAX);

        currDistance[src] = tempDistance[src] = 0;
        for (int i = 1; i <= k + 1; i++)
        {
            for (auto &e : flights)
            {
                if (currDistance[e[0]] != INT_MAX && (currDistance[e[0]] + e[2] < tempDistance[e[1]]))
                {
                    tempDistance[e[1]] = currDistance[e[0]] + e[2];
                }
            }

            for (int j = 0; j < n; j++)
            {
                currDistance[j] = tempDistance[j];
            }
        }

        return currDistance[dst] == INT_MAX ? -1 : currDistance[dst];
    }
};