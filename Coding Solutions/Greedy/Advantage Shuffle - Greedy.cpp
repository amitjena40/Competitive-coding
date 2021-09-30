class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        priority_queue<pair<int, int>> pq;
        sort(nums1.begin(), nums1.end());
        int l = 0, r = n - 1;
        for (int i = 0; i < n; i++) {
            pq.push({nums2[i], i});
        }

        vector<int> ans(n);
        while (!pq.empty()) {
            int x = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if (nums1[r] > x) {
                ans[idx] = nums1[r--];
            }
            else {
                ans[idx] = nums1[l++];
            }
        }

        return ans;
    }
};