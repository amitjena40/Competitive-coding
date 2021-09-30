vector<int> find(int arr[], int n , int x )
{
    // code here
    int lo = 0, hi = n - 1, first = -1, last = -1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == x)
        {
            first = mid;
            hi = mid - 1;
        }
        else if (arr[mid] < x)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    lo = 0, hi = n - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == x)
        {
            last = mid;
            lo = mid + 1;
        }
        else if (arr[mid] < x)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return {first, last};
}