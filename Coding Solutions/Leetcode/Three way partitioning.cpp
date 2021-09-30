//User function template for C++

class Solution {
public:
    void threeWayPartition(vector<int>& array, int a, int b)
    {
        // code here
        int start = 0, n = array.size();
        for (int i = 0; i < n; i++)
        {
            if (array[i] < a)
            {
                swap(array[i], array[start++]);
            }
        }

        for (int i = start; i < n; i++)
        {
            if (array[i] <= b && array[i] >= a)
            {
                swap(array[i], array[start++]);
            }
        }

        for (int i = start; i < n; i++)
        {
            if (array[i] > b)
            {
                swap(array[i], array[start++]);
            }
        }
    }
};