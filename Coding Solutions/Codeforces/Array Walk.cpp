#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

ll dp[100002][6][3];

ll maxP(ll a[], ll n, ll k, ll z, ll curr, ll left)
{
	if (k == 0 || curr >= n || curr < 0)
	{
		return 0;
	}

	if (dp[curr][z][left] > -1)
	{
		return dp[curr][z][left];
	}

	ll ans1 = 0, ans2 = 0;
	ans1 = maxP(a, n, k - 1, z, curr + 1, 0);

	if (left == 0 && z > 0)
	{
		ans2 = maxP(a, n, k - 1, z - 1, curr - 1, 1);
	}

	dp[curr][z][left] = a[curr] + max(ans1, ans2);
	return dp[curr][z][left];
}

void solve()
{
	ll n, k, z;
	cin >> n >> k >> z;
	ll a[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j <= 5; j++)
		{
			for (ll k = 0; k < 2; k++)
			{
				dp[i][j][k] = -1;
			}
		}
	}
	//memset(dp, -1, sizeof(dp));
	ll left = 0;
	ll ans = a[0] + maxP(a, n, k, z, 1, left);
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