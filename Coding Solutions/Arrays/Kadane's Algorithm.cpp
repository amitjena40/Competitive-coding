// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n) {

    // Your code here
    int curr_sum = 0, max_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];
        if (curr_sum > max_sum)
        {
            max_sum = curr_sum;
        }

        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
    }

    return max_sum;
}