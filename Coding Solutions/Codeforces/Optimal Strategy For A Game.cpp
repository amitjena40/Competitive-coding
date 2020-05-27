#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

ll dp[100][100];

ll fn(ll a[], ll i, ll j)
{
	if (i == j)
	{
		return a[i];
	}

	if (i + 1 == j)
	{
		return max(a[i], a[j]);
	}

	if (dp[i][j] > -1)
	{
		return dp[i][j];
	}

	ll option1 = a[i] + min(fn(a, i + 1, j - 1), fn(a, i + 2, j));
	ll option2 = a[j] + min(fn(a, i, j - 2), fn(a, i + 1, j - 1));
	dp[i][j] = max(option1, option2);
	return dp[i][j];
}

void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << fn(a, 0, n - 1) << "\n";
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