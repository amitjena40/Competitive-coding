class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (dict.find(endWord) == dict.end())
        {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);
        int level = 0;


        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                string curr = q.front();
                q.pop();
                if (curr == endWord)
                {
                    return level + 1;
                }
                dict.erase(curr);
                for (int j = 0; j < curr.size(); j++)
                {
                    char og = curr[j];
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        curr[j] = ch;
                        if (dict.find(curr) != dict.end())
                        {
                            q.push(curr);
                        }
                    }
                    curr[j] = og;
                }
            }

            level++;
        }

        return 0;
    }
};