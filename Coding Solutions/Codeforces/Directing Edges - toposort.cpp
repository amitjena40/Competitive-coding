#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

vector<ll> topoSort(vector<vector<ll>> adj)
{
	ll n = adj.size();
	vector<ll> inDeg(n, 0);
	for (ll i = 0; i < n; i++)
	{
		for (auto x : adj[i])
		{
			inDeg[x]++;
		}
	}

	queue<ll> q;
	for (ll i = 0; i < n; i++)
	{
		if (!inDeg[i])
		{
			q.push(i);
		}
	}

	vector<ll> ans;
	while (!q.empty())
	{
		ll v = q.front();
		q.pop();
		ans.PB(v);
		for (auto x : adj[v])
		{
			inDeg[x]--;
			if (inDeg[x] == 0)
			{
				q.push(x);
			}
		}
	}

	return ans;
}

void solve()
{
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> adj(n);
	vector<pair<ll, ll>> edges;
	for (ll i = 0; i < m; i++)
	{
		ll t, x, y;
		cin >> t >> x >> y;
		x--;
		y--;
		edges.PB({x, y});
		if (t == 1)
		{
			adj[x].PB(y);
		}
	}

	vector<ll> seq = topoSort(adj);
	if (seq.size() < n)
	{
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	vector<ll> idx(n, -1);
	for (ll i = 0; i < n; i++)
	{
		idx[seq[i]] = i;
	}

	for (auto it : edges)
	{
		if (idx[it.first] > idx[it.second])
		{
			swap(it.first, it.second);
		}

		cout << it.first + 1 << " " << it.second + 1 << "\n";
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