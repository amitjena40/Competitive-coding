#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, m;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cin >> m;

	sort(a, a + n);
	ll ans = INT_MAX;
	for (ll i = m - 1; i < n; i++)
	{
		ans = min(ans, a[i] - a[i - m + 1]);
	}

	cout << ans << "\n";
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
	t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}