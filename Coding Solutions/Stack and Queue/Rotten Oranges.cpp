#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll r, c;
	cin >> r >> c;
	ll pos[r][c];
	queue<pair<ll, ll>> q;
	for (ll i = 0; i < r; i++)
	{
		for (ll j = 0; j < c; j++)
		{
			cin >> pos[i][j];
			if (pos[i][j] == 2)
			{
				q.push(make_pair(i, j));
			}
		}
	}

	q.push(make_pair(-1, -1));
	ll ans = 0;
	while (!q.empty())
	{
		pair<ll, ll> p = q.front();
		q.pop();
		ll x = p.first, y = p.second;
		if (x == -1 && y == -1)
		{
			if (!q.empty())
			{q.push(make_pair(-1, -1)); ans++;}
			//ans++;
			continue;
		}

		if (x >= 1)
		{
			if (pos[x - 1][y] == 1)
			{
				pos[x - 1][y] = 2;
				q.push(make_pair(x - 1, y));
			}
		}

		if (x < r - 1)
		{
			if (pos[x + 1][y] == 1)
			{
				pos[x + 1][y] = 2;
				q.push(make_pair(x + 1, y));
			}
		}

		if (y >= 1)
		{
			if (pos[x][y - 1] == 1)
			{
				pos[x][y - 1] = 2;
				q.push(make_pair(x, y - 1));
			}
		}

		if (y < c - 1)
		{
			if (pos[x][y + 1] == 1)
			{
				pos[x][y + 1] = 2;
				q.push(make_pair(x, y + 1));
			}
		}
	}

	ll flag = 0;

	for (ll i = 0; i < r; i++)
	{
		for (ll j = 0; j < c; j++)
		{
			if (pos[i][j] == 1)
			{
				flag = 1;
				break;
			}
		}

		if (flag)
		{
			break;
		}
	}

	if (flag == 0)
	{
		cout << ans << "\n";
	}
	else
	{
		cout << "-1\n";
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