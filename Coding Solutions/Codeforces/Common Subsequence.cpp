#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, m;
	cin >> n >> m;
	ll a[n], b[m];
	map<ll, ll> mp;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		mp[a[i]]++;
	}

	ll flag = 0, idx = -1;
	for (ll i = 0; i < m; i++)
	{
		cin >> b[i];
		if (flag)
		{
			continue;
		}

		if (mp[b[i]] > 0)
		{
			flag = 1;
			idx = i;
		}
	}

	if (flag == 1)
	{
		cout << "YES\n";
		cout << 1 << " " << b[idx] << "\n";
	}
	else
		cout << "NO\n";
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