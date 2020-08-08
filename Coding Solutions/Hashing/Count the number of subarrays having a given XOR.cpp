#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll a[n], xorArr[n], curr_xor = 0;
	unordered_map<ll , ll> mp;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		curr_xor = curr_xor ^ a[i];
		xorArr[i] = curr_xor;
	}

	ll m;
	cin >> m;
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		ll temp = m ^ xorArr[i];
		ans += mp[temp];
		if (xorArr[i] == m)
		{
			ans++;
		}

		mp[xorArr[i]]++;
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