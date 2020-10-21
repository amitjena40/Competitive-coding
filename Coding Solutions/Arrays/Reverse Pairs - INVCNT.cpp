class Solution {
public:
    int merge(vector<int> &nums, int n, vector<int> &left, int n1, vector<int> &right, int n2)
    {
        int count = 0;
        int a = 0, b = 0;
        while (a < n1)
        {
            while (b < n2 && left[a] > 2LL * right[b])
            {
                b++;
            }

            count += b;
            a++;
        }

        int i = 0, j = 0, k = 0;
        while (i < n1 && j < n2)
        {
            if (left[i] < right[j])
            {
                nums[k++] = left[i++];
            }
            else
            {
                nums[k++] = right[j++];
            }
        }

        while (i < n1)
        {
            nums[k++] = left[i++];
        }

        while (j < n2)
        {
            nums[k++] = right[j++];
        }

        return count;
    }

    int mSort(vector<int> &nums, int n)
    {
        if (n < 2)
        {
            return 0;
        }

        int mid = n / 2;
        vector<int> left(mid);
        vector<int> right(n - mid);

        for (int i = 0; i < mid; i++)
        {
            left[i] = nums[i];
        }

        for (int i = mid; i < n; i++)
        {
            right[i - mid] = nums[i];
        }

        return mSort(left, mid) + mSort(right, n - mid) + merge(nums, n, left, mid, right, n - mid);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ans = mSort(nums, n);
        return ans;
    }
};