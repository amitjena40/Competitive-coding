int sb(int arr[], int n, int x)
{
    // Your code goes here
    int ans = n;
    int curr_sum = 0;

    for (int i = 0, j = 0; j < n; j++)
    {
        curr_sum += arr[j];
        while (curr_sum > x)
        {
            ans = min(ans, j - i + 1);
            curr_sum -= arr[i];
            i++;
        }
    }

    return ans;
}