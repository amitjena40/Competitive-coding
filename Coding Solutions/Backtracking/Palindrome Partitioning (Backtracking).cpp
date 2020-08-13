class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> answers;
        if (s.empty())
        {
            return answers;
        }

        vector<string> possAns;
        partition(0, s, possAns, answers);
        return answers;
    }

    void partition(int index, string s, vector<string> possAns, vector<vector<string>> &answers)
    {
        if (index == s.size())
        {
            answers.push_back(possAns);
            return;
        }

        for (int i = index; i < s.size(); i++)
        {
            if (isPallindrome(s, index, i))
            {
                possAns.push_back(s.substr(index, i - index + 1));
                partition(i + 1, s, possAns, answers);
                possAns.pop_back();
            }
        }
    }

    bool isPallindrome(string s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
            {
                return false;
            }
        }

        return true;
    }
};