#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

int trap(vector<int>& height) {
    int n = height.size();

    if (n == 0)
    {
        return 0;
    }

    int left[n], right[n], max_height = 0;
    for (int i = 0; i < n; i++)
    {
        left[i] = max(max_height, height[i]);
        max_height = left[i];
    }

    max_height = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        right[i] = max(max_height, height[i]);
        max_height = right[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(left[i], right[i]) - height[i];
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> height;
    for (int i = 0; i < n; i++)
    {
        int item;
        cin >> item;
        height.PB(item);
    }

    cout << trap(height) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}