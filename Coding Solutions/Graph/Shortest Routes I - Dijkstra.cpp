#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, m;
	cin >> n >> m;
	vector<vector<pair<ll, ll>>> G(n + 1);

	while (m--)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		G[a].push_back({b, c});
	}

	vector<ll> distance(n + 1, LLONG_MAX);
	vector<bool> visited(n + 1, false);
	distance[1] = 0;

	priority_queue<pair<ll, ll>> pq;
	pq.push({0, 1});

	while (!pq.empty())
	{
		ll p = pq.top().second;
		pq.pop();
		if (visited[p])
			continue;

		visited[p] = true;
		for (auto e : G[p])
		{
			ll w = e.second, v = e.first;
			if (distance[p] + w < distance[v])
			{
				distance[v] = distance[p] + w;
				pq.push({ -distance[v], v});
			}
		}
	}

	for (ll i = 1; i <= n; i++)
	{
		cout << distance[i] << " ";
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