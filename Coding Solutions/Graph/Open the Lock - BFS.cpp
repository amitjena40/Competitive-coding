class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, bool> visited;
        for (auto x : deadends) {
            visited[x] = true;
        }

        if (visited["0000"]) {
            return -1;
        }
        else {
            visited["0000"] = true;
        }

        queue<string> q;
        q.push("0000");
        int ans = 0;
        while (1) {
            int l = q.size();
            if (l == 0)return -1;

            while (l--) {
                string curr = q.front();
                q.pop();
                if (curr == target) {
                    return ans;
                }

                for (int i = 0; i < 4; i++) {
                    string dup1 = curr, dup2 = curr;
                    int num = curr[i] - '0';
                    dup1[i] = (num - 1 + 10) % 10 + '0';
                    dup2[i] = (num + 1) % 10 + '0';
                    if (!visited[dup1]) {q.push(dup1); visited[dup1] = true;}
                    if (!visited[dup2]) {q.push(dup2); visited[dup2] = true;}
                }
            }
            ans++;
        }

        return 0;
    }
};