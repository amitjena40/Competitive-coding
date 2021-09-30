class Solution {
public:
    int util(int idx, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp, int prev1, int prev2, int swapped)
    {
        if (idx == nums1.size())
        {
            return 0;
        }

        if (dp[idx][swapped] != -1)
        {
            return dp[idx][swapped];
        }

        int temp = INT_MAX;

        if (nums1[idx] > prev1 && nums2[idx] > prev2)
            temp = min(temp, util(idx + 1, nums1, nums2, dp, nums1[idx], nums2[idx], 0));

        swap(nums1[idx], nums2[idx]);
        if (nums1[idx] > prev1 && nums2[idx] > prev2)
            temp = min(temp, util(idx + 1, nums1, nums2, dp, nums1[idx], nums2[idx], 1) + 1);
        swap(nums1[idx], nums2[idx]);

        return dp[idx][swapped] = temp;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(2, -1));

        return util(0, nums1, nums2, dp, -1, -1, 0);
    }
};