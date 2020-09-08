class Solution {
public:
#define pi pair< int, vector<int> >

    int dist(vector<int> v)
    {
        return v[0] * v[0] + v[1] * v[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pi> pq;
        pq.push({dist(points[0]), points[0]});

        int n = points.size();
        for (int i = 1; i < n; i++)
        {
            if (pq.size() < K)
            {
                pq.push({dist(points[i]), points[i]});
            }
            else
            {
                if (dist(points[i]) < pq.top().first)
                {
                    pq.pop();
                    pq.push({dist(points[i]), points[i]});
                }
            }
        }

        vector<vector<int>> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};