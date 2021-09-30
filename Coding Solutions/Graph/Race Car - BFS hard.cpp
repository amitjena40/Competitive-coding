class Solution {
public:
    int racecar(int target) {
        queue<pair<int, int>> q;
        unordered_map<int, unordered_map<int, bool>> visited;
        q.push({0, 1});
        int ans = 0;
        visited[0][1] = true;

        while (1)
        {
            int l = q.size();
            while (l--)
            {
                pair<int, int> curr = q.front();
                q.pop();

                if (curr.first == target)
                {
                    return ans;
                }

                vector<pair<int, int>> temp;

                if (abs(target - (curr.first + curr.second)) < target)
                {
                    temp.push_back({curr.first + curr.second, 2 * curr.second});
                }

                temp.push_back({curr.first, curr.second > 0 ? -1 : 1});

                for (auto x : temp)
                {
                    if (!visited[x.first][x.second])
                    {
                        q.push({x.first, x.second});
                        visited[x.first][x.second] = true;
                    }
                }
            }

            ans++;
        }

        return -1;
    }
};