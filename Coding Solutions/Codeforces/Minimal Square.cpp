#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

void solve()
{
    ll a, b;
    cin >> a >> b;
    ll side = min(a, b);
    if (2 * side < max(a, b))
    {
        cout << max(a, b)*max(a, b) << "\n";
    }
    else
    {
        cout << 4 * side*side << "\n";
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
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