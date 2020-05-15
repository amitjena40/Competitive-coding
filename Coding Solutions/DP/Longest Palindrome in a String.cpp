#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

void solve()
{
	string s;
	cin >> s;
	ll n = s.size(), index = 0, max_len = 1;
	bool dp[n][n];
	memset(dp, 0, sizeof(dp));

	for (ll i = 0; i < n; i++)
	{
		dp[i][i] = true;
	}

	for (ll i = 0; i < n - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			dp[i][i + 1] = true;
			if (2 > max_len)
			{
				max_len = 2;
				index = i;
			}
		}
	}

	for (ll L = 3; L <= n; L++)
	{
		for (ll i = 0; i <= n - L; i++)
		{
			ll j = i + L - 1;
			if (s[i] == s[j] && dp[i + 1][j - 1])
			{
				dp[i][j] = true;
				if (L > max_len)
				{
					max_len = L;
					index = i;
				}

			}
		}
	}
	string ans = s.substr(index, max_len);
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