#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back
using namespace std;

ll screen[1000][1000];

void util(ll x, ll y, ll k, ll n, ll m)
{
	ll match = screen[x][y];
	screen[x][y] = k;
	if (y >= 1 && screen[x][y - 1] == match)
	{
		util( x, y - 1, k, n, m);
	}

	if (y < m - 1 && screen[x][y + 1] == match)
	{
		util(x, y + 1, k, n, m);
	}

	if (x >= 1 && screen[x - 1][y] == match)
	{
		util( x - 1, y, k, n, m);
	}

	if (x < n - 1 && screen[x + 1][y] == match)
	{
		util(x + 1, y, k, n, m);
	}
}

void solve()
{
	ll n, m;
	cin >> n >> m;
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < m; j++)
		{
			cin >> screen[i][j];
		}
	}

	ll x, y, k;
	cin >> x >> y >> k;
	util(x, y, k, n, m);
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < m; j++)
		{
			cout << screen[i][j] << " ";
		}
	}
	cout << "\n";
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