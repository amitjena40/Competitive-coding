#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, m;
	cin >> n >> m;
	vector<string> v(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	pair<ll, ll> start;
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < m; j++)
		{
			if (v[i][j] == 'A')
			{
				start = {i, j};
				break;
			}
		}
	}

	string path = "";
	queue<pair<string, pair<ll, ll>>> q;
	q.push(make_pair(path, start));

	while (!q.empty())
	{
		string curr = q.front().first;
		ll x = q.front().second.first, y = q.front().second.second;
		q.pop();

		if (v[x][y] == 'B')
		{
			cout << "YES\n";
			cout << curr.size() << "\n";
			cout << curr << "\n";
			return;
		}

		v[x][y] = 'X';

		if (x - 1 >= 0 && (v[x - 1][y] == '.' || v[x - 1][y] == 'B'))
		{
			q.push({curr + "U", {x - 1, y}});
		}

		if (x + 1 < n && (v[x + 1][y] == '.' || v[x + 1][y] == 'B'))
		{
			q.push({curr + "D", {x + 1, y}});
		}

		if (y - 1 >= 0 && (v[x][y - 1] == '.' || v[x][y - 1] == 'B'))
		{
			q.push({curr + "L", {x, y - 1}});
		}

		if (y + 1 < m && (v[x][y + 1] == '.' || v[x][y + 1] == 'B'))
		{
			q.push({curr + "R", {x, y + 1}});
		}
	}

	cout << "NO\n";
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