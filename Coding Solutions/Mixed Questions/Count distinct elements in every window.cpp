vector <int> countDistinct (int A[], int n, int k)
{
    //code here.
    int distinct = 0, i;
    unordered_map<int, int> m;
    vector<int> ans;
    for (i = 0; i < k; i++)
    {
        if (m[A[i]] == 0)
        {
            distinct++;
        }
        m[A[i]]++;
    }
    ans.push_back(distinct);
    for (; i < n; i++)
    {
        if (m[A[i]] == 0)
        {
            distinct++;
        }
        m[A[i]]++;
        m[A[i - k]]--;
        if (m[A[i - k]] == 0)
        {
            distinct--;
        }
        ans.push_back(distinct);
    }
    return ans;
}