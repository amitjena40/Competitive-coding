class Solution {
public:
    void util(vector<string> &ans, string curr, int open, int close, int maxpair)
    {
        if (curr.size() == 2 * maxpair)
        {
            ans.push_back(curr);
            return;
        }

        if (open < maxpair)
        {
            util(ans, curr + "(", open + 1, close, maxpair);
        }

        if (close < open)
        {
            util(ans, curr + ")", open, close + 1, maxpair);
        }
    }


    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        util(ans, "", 0, 0, n);
        return ans;
    }
};