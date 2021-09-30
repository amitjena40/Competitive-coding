#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void DFS(ll curr, ll parent, vector<bool> &visited, vector<vector<ll>> &G, vector<pair<ll, ll>> &critical,
         ll timer, vector<ll> &in, vector<ll> &low)
{
	visited[curr] = true;
	in[curr] = timer;
	low[curr] = timer;
	timer++;

	for (auto x : G[curr])
	{
		if (x == parent)
		{
			continue;
		}
		else if (visited[x])
		{

			low[curr] = min(low[curr], in[x]);
		}
		else
		{
			DFS(x, curr, visited, G, critical, timer, in, low);
			if (low[x] > in[curr])
			{
				critical.push_back({curr, x});
			}
			low[curr] = min(low[curr], low[x]);
		}
	}
}

void solve()
{
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> G(n + 1);
	while (m--)
	{
		ll a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	vector<pair<ll, ll>> critical;
	vector<bool> visited(n + 1, false);
	ll timer = 0;
	vector<ll> in(n + 1), low(n + 1);
	DFS(1, -1, visited, G, critical, timer, in, low);

	if (critical.size() == 0)
	{
		cout << "Sin bloqueos\n";
		return;
	}

	cout << critical.size() << "\n";
	for (ll i = 0; i < critical.size(); i++)
	{
		if (critical[i].first > critical[i].second)
		{
			swap(critical[i].first, critical[i].second);
		}
	}

	sort(critical.begin(), critical.end());

	for (auto x : critical)
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
	t = 1;
	cin >> t;
	for (ll i = 1; i <= t; i++)
	{
		cout << "Caso #" << i << "\n";
		solve();
	}
	return 0;
}