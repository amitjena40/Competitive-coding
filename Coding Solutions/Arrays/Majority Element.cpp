class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (auto x : nums)
        {
            if (count == 0)
            {
                candidate = x;
            }

            if (candidate == x)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        return candidate;
    }
};