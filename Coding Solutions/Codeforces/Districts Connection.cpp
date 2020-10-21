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
	ll idx = -1;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	vector<pair<ll, ll>> ans;
	for (ll i = 1; i < n; i++)
	{
		if (a[i] != a[0])
		{
			idx = i;
			ans.PB({1, i + 1});
		}
	}

	if (idx == -1)
	{
		cout << "NO\n";
		return;
	}

	for (ll i = 1; i < n; i++)
	{
		if (a[i] == a[0])
		{
			ans.PB({i + 1, idx + 1});
		}
	}

	cout << "YES\n";
	for (auto x : ans)
	{
		cout << x.first << " " << x.second << "\n";
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