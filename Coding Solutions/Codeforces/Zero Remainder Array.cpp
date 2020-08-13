#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, k;
	cin >> n >> k;
	ll mx = 0;
	map<ll, ll> m;
	for (ll i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
		x = x % k;
		if (x)
		{
			m[k - x]++;
		}
	}

	for (auto it = m.begin(); it != m.end(); ++it)
	{
		ll x = (it->second - 1) * k + it->first;
		mx = max(mx, x);
	}

	if (mx)
	{
		mx++;
	}

	cout << mx << "\n";
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