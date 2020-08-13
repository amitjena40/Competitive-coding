#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	ll ans = a[0];
	ll imin = a[0], imax = a[0];
	for (ll i = 1; i < n; i++)
	{
		if (a[i] < 0)
		{
			swap(imax, imin);
		}

		imax = max(a[i], ((imax % mod) * (a[i] % mod)) % mod);
		imin = min(a[i], ((imin % mod) * (a[i] % mod)) % mod);
		ans = max(ans, imax);
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
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}