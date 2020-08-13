#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

ll dp[1001][1001];

ll fn(ll val[], ll wt[], ll n, ll W)
{
	if (W == 0 || n == 0)
	{
		return 0;
	}

	if (dp[n][W] > -1)
	{
		return dp[n][W];
	}

	ll op1 = 0;
	if (wt[0] <= W)
		op1 = val[0] + fn(val + 1, wt + 1, n - 1, W - wt[0]);

	ll op2 = 0;
	op2 = fn(val + 1, wt + 1, n - 1, W);

	ll ans = max(op1, op2);
	dp[n][W] = ans;
	return ans;
}

void solve()
{
	ll n, W;
	cin >> n >> W;
	ll val[n], wt[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> val[i];
	}

	for (ll i = 0; i < n; i++)
	{
		cin >> wt[i];
	}

	memset(dp, -1, sizeof(dp));
	ll ans = fn(val, wt, n, W);
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