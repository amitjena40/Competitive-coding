class Solution {
public:
    static bool cmp(vector<int> item1, vector<int> item2)
    {

        return item1[0] < item2[0];

    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        if (intervals.empty())
        {
            return ans;
        }

        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> inter(2);
        inter[0] = intervals[0][0];
        inter[1] = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= inter[1])
            {
                inter[1] = max(inter[1], intervals[i][1]);
            }
            else if (intervals[i][0] > inter[1])
            {
                ans.push_back(inter);
                inter[0] = intervals[i][0];
                inter[1] = intervals[i][1];
            }
        }

        ans.push_back(inter);
        return ans;
    }
};