#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll p[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> p[i];
	}

	ll dp[n][n];
	memset(dp, 0, sizeof(dp));
	for (ll l = 1; l < n - 1; l++)
	{
		for (ll i = 1; i <= n - l; i++)
		{
			ll j = i + l;
			dp[i][j] = INT_MAX;
			for (ll k = i; k < j; k++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j]);
			}
		}
	}

	cout << dp[1][n - 1] << "\n";
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