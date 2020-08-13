#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll a[n], b[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	map<ll, ll> id;
	for (ll i = 0; i < n; i++)
	{
		cin >> b[i];
		id[b[i]] = i;
	}

	ll right[n], ans = INT_MIN;
	memset(right, 0, sizeof(right));
	for (ll i = 0; i < n; i++)
	{
		ll k = id[a[i]] - i;
		if (k < 0)
		{
			k = n - abs(k);
		}
		right[k]++;
	}

	for (ll i = 0; i < n; i++)
	{
		ans = max(ans, right[i]);
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
	/*ll t;
	cin >> t;
	while (t--)
	{
		solve();
	}*/
	solve();
	return 0;
}