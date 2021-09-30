class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumB = accumulate(bobSizes.begin(), bobSizes.end(), 0);

        if (sumA < sumB) {
            vector<int> v =  fairCandySwap(bobSizes, aliceSizes);
            reverse(v.begin(), v.end());
            return v;
        }

        unordered_set<int> s;
        for (int x : aliceSizes) {
            s.insert(x);
        }

        int diff = (sumA - sumB) / 2;
        for (int x : bobSizes) {
            if (s.count(x + diff)) {
                return {x + diff, x};
            }
        }

        return {};
    }
};