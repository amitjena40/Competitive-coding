#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

ll fn(ll v, ll &ans, vector<vector<ll>> &G, vector<bool> &visited)
{
	visited[v] = true;

	ll temp1 = 0, temp2 = 0;
	vector<ll> d;
	for (auto x : G[v])
	{
		if (!visited[x])
			d.push_back(fn(x, ans, G, visited));
	}
	sort(d.begin(), d.end(), greater<ll>());

	if (d.size() >= 1)
	{
		temp1 = d[0];
	}

	if (d.size() >= 2)
	{
		temp2 = d[1];
	}

	ans = max(ans, temp1 + temp2);
	return max(temp1, temp2) + 1;
}

void solve()
{
	ll n;
	cin >> n;
	vector<vector<ll>> G(n + 1);

	for (ll i = 0; i < n - 1; i++)
	{
		ll a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	vector<bool> visited(n + 1, false);
	ll ans = 0;
	fn(1, ans, G, visited);
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
	ll t;
	t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}