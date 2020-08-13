#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll V;
	cin >> V;
	ll adj[V][V];
	for (ll i = 0; i < V; i++)
	{
		for (ll j = 0; j < V; j++)
		{
			cin >> adj[i][j];
		}
	}

	for (ll k = 0; k < V; k++)
	{
		for (ll i = 0; i < V; i++)
		{
			for (ll j = 0; j < V; j++)
			{
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}

	for (ll i = 0; i < V; i++)
	{
		for (ll j = 0; j < V; j++)
		{
			if (adj[i][j] >= 1e7)
			{
				cout << "INF ";
			}
			else
			{
				cout << adj[i][j] << " ";
			}
		}
		cout << "\n";
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