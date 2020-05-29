#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	string s;
	cin >> s;

	ll n = s.size();
	bool dp[n][n];

	for (ll i = 0; i < n; i++)
	{
		dp[i][i] = true;
	}

	for (ll L = 2; L <= n; L++)
	{
		for (ll i = 0; i < n - L + 1; i++)
		{
			ll j = i + L - 1;
			if (L == 2)
			{
				dp[i][j] = (s[i] == s[j]);
			}
			else
			{
				dp[i][j] = (s[i] == s[j]) && (dp[i + 1][j - 1]);
			}
		}
	}

	ll c[n];
	c[0] = 0;
	for (ll i = 1; i < n; i++)
	{
		if (!dp[0][i])
		{
			c[i] = INT_MAX;
			for (ll j = 0; j < i; j++)
			{
				if (dp[j + 1][i] && c[i] > c[j] + 1)
				{
					c[i] = c[j] + 1;
				}
			}
		}
		else
		{
			c[i] = 0;
		}
	}
	cout << c[n - 1] << "\n";
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