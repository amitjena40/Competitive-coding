class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> possAns;
        fn(nums, 0, possAns, ans);
        return ans;
    }

    void fn(vector<int> &nums, int index, vector<int> possAns, vector<vector<int>> &ans)
    {
        ans.push_back(possAns);
        for (int i = index; i < nums.size(); i++)
        {
            possAns.push_back(nums[i]);
            fn(nums, i + 1, possAns, ans);
            possAns.pop_back();
        }
    }
};

//Solution for Subsets II
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> possAns;
        fn(nums, 0, possAns, ans);
        return ans;
    }

    void fn(vector<int> &nums, int index, vector<int> possAns, vector<vector<int>> &ans)
    {
        ans.push_back(possAns);
        for (int i = index; i < nums.size(); i++)
        {
            if (i != index && nums[i] == nums[i - 1])
            {
                continue;
            }
            possAns.push_back(nums[i]);
            fn(nums, i + 1, possAns, ans);
            possAns.pop_back();
        }
    }
};