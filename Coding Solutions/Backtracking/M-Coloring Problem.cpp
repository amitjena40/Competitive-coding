#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;


bool DFS(ll curr, ll n, ll m, vector<vector<ll>> &v, ll colour[])
{
	if (curr == n + 1)
	{
		return true;
	}

	unordered_set<ll> s;
	for (ll i = 0; i < v[curr].size(); i++)
	{
		s.insert(colour[v[curr][i]]);
	}

	for (ll k = 0; k < m; k++)
	{
		if (s.find(k) == s.end())
		{
			colour[curr] = k;
			if (DFS(curr + 1, n, m, v, colour))
			{
				return true;
			}

			colour[curr] = -1;
		}
	}

	return false;
}

void solve()
{
	ll n, m, e;
	cin >> n >> m >> e;
	vector<vector<ll>> v(n + 1);

	for (ll i = 0; i < e; i++)
	{
		ll x, y;
		cin >> x >> y;
		v[x].PB(y);
		v[y].PB(x);
	}

	ll colour[n + 1];
	memset(colour, -1, sizeof(colour));
	if (DFS(1, n, m, v, colour))
	{
		cout << "1\n";
	}
	else
	{
		cout << "0\n";
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