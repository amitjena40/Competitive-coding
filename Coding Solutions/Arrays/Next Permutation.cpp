class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int id1 = -1, id2 = -1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                id1 = i;
                break;
            }
        }

        if (id1 == -1)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for (int i = nums.size() - 1; i > id1; i--)
            {
                if (nums[i] > nums[id1])
                {
                    id2 = i;
                    break;
                }
            }

            swap(nums[id1], nums[id2]);
            reverse(nums.begin() + id1 + 1, nums.end());
        }
    }
};