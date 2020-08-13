#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, m;
	cin >> n >> m;
	string s[n];

	for (ll i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < m; j++)
		{
			if (i == n - 1 && j == m - 1)
			{
				continue;
			}

			if (s[i][j] == 'R')
			{
				if (j + 1 < m)
				{
					continue;
				}

				s[i][j] = 'D';
				ans++;
			}
			else if (s[i][j] == 'D')
			{
				if (i + 1 < n)
				{
					continue;
				}

				s[i][j] = 'R';
				ans++;
			}
		}
	}

	cout << ans << "\n";
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