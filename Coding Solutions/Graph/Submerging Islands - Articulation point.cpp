#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void DFS(ll curr, vector<bool> &visited, vector<vector<ll>> &G, ll &timer,
         vector<ll> &in, vector<ll> &low, unordered_set<ll> &ans, ll parent = -1)
{
	visited[curr] = true;
	ll children = 0;
	in[curr] = low[curr] = timer;
	timer++;

	for (ll x : G[curr])
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
			DFS(x, visited, G, timer, in, low, ans, curr);
			children++;
			if (low[x] >= in[curr] && parent != -1)
			{
				ans.insert(curr);
			}
			low[curr] = min(low[curr], low[x]);
		}
	}

	if (parent == -1 && children > 1)
	{
		ans.insert(curr);
	}
}

ll solve()
{
	ll n, m;
	cin >> n >> m;
	if (n == 0 && m == 0)
	{
		return 1;
	}

	vector<vector<ll>> G(n + 1);
	while (m--)
	{
		ll a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	vector<bool> visited(n + 1, false);
	ll timer = 0;
	vector<ll> in(n + 1), low(n + 1);
	unordered_set<ll> ans;
	DFS(1, visited, G, timer, in, low, ans);
	cout << ans.size() << "\n";
	return 0;
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
	while (1)
	{
		ll r = solve();
		if (r == 1)
			break;
	}
	return 0;
}