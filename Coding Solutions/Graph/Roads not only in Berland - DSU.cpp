#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

ll find(ll x, vector<ll> &link)
{
	if (x == link[x])
	{
		return x;
	}

	return link[x] = find(link[x], link);
}

bool same(ll a, ll b, vector<ll> &link)
{
	return find(a, link) == find(b, link);
}

void unite(ll a, ll b, vector<ll> &link)
{
	ll p1 = find(a, link);
	ll p2 = find(b, link);

	link[p2] = p1;
}

void solve()
{
	ll n;
	cin >> n;
	vector<ll> link(n + 1);
	for (ll i = 0; i <= n; i++)
	{
		link[i] = i;
	}

	vector<vector<ll>> unused, tobuilt;
	for (ll i = 0; i < n - 1; i++)
	{
		ll a, b;
		cin >> a >> b;
		if (same(a, b, link))
		{
			unused.push_back({a, b});
		}
		else
		{
			unite(a, b, link);
		}
	}

	for (ll i = 2; i <= n; i++)
	{
		if (!same(1, i, link))
		{
			tobuilt.push_back({1, i});
			unite(1, i, link);
		}
	}

	cout << unused.size() << "\n";

	for (ll i = 0; i < unused.size(); i++)
	{
		cout << unused[i][0] << " " << unused[i][1] << " " << tobuilt[i][0] << " " << tobuilt[i][1] << "\n";
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
	t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}