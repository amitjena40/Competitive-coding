int maxLen(int a[], int n)
{
    // Your code here
    int maxLen = 0;
    unordered_map<int, int> m;
    int sum = 0;
    m[0] = -1;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (m.find(sum) != m.end())
        {
            maxLen = max(maxLen, i - m.find(sum)->second);
        }
        else
        {
            m[sum] = i;
        }
    }

    return maxLen;
}