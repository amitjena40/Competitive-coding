#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, e;
	cin >> n >> e;
	map <pair<ll, ll>, ll> g;
	for (ll i = 0; i < e; i++)
	{
		ll x, y, z;
		cin >> x >> y >> z;
		g[make_pair(x, y)] = z;
	}

	ll distance[n];
	for (ll i = 0; i < n; i++)
	{
		distance[i] = INT_MAX;
	}

	distance[0] = 0;
	for (ll i = 0; i < n - 1; i++)
	{
		for (auto it = g.begin(); it != g.end(); it++)
		{
			if (distance[it->first.first] + it->second < distance[it->first.second])
			{
				distance[it->first.second] = distance[it->first.first] + it->second;
			}
		}
	}

	ll flag = 0;
	for (auto it = g.begin(); it != g.end(); it++)
	{
		if (distance[it->first.first] + it->second < distance[it->first.second])
		{
			flag = 1;
			distance[it->first.second] = distance[it->first.first] + it->second;
		}
	}

	if (flag == 0)
	{
		cout << "0\n";
	}
	else
	{
		cout << "1\n";
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