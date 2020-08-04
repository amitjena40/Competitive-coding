#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, k;
	cin >> n >> k;
	ll rq, cq;
	cin >> rq >> cq;
	vector<pair<ll, ll>> v;
	while (k--)
	{
		ll x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));

	}

	map<pair<ll, ll>, bool> m;
	for (ll i = 0; i < v.size(); i++)
	{
		m[v[i]] = true;
	}

	ll ans = 0;
	for (ll x = rq + 1; x <= n; x++)
	{
		if (m[make_pair(x, cq)])
		{
			break;
		}
		ans++;
	}

	for (ll x = rq - 1; x >= 1; x--)
	{
		if (m[make_pair(x, cq)])
		{
			break;
		}
		ans++;
	}

	for (ll y = cq - 1; y >= 1; y--)
	{
		if (m[make_pair(rq, y)])
		{
			break;
		}
		ans++;
	}

	for (ll y = cq + 1; y <= n; y++)
	{
		if (m[make_pair(rq, y)])
		{
			break;
		}
		ans++;
	}

	for (ll x = rq + 1, y = cq - 1; x <= n && y >= 1; x++, y--)
	{
		if (m[make_pair(x, y)])
		{
			break;
		}
		ans++;
	}

	for (ll x = rq + 1, y = cq + 1; x <= n && y <= n; x++, y++)
	{
		if (m[make_pair(x, y)])
		{
			break;
		}
		ans++;
	}

	for (ll x = rq - 1, y = cq - 1; x >= 1 && y >= 1; x--, y--)
	{
		if (m[make_pair(x, y)])
		{
			break;
		}
		ans++;
	}

	for (ll x = rq - 1, y = cq + 1; x >= 1 && y <= n; x--, y++)
	{
		if (m[make_pair(x, y)])
		{
			break;
		}
		ans++;
	}

	cout << ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//ll t;
	//cin >> t;
	//while (t--)
	//{
	solve();
	//}
	return 0;
}