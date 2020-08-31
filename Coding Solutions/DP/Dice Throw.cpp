#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

ll dp[51][51];

void fn(ll &ans, ll count, ll m, ll n, ll x)
{
	if (count > n)
	{
		return;
	}

	if (x == 0 and count == n)
	{
		ans++;
		return;
	}

	for (ll i = 1; i <= m; i++)
	{
		if (i <= x)
		{
			fn(ans, count + 1, m, n, x - i);
		}
		else
		{
			break;
		}
	}
}

void solve()
{
	ll m, n, x;
	cin >> m >> n >> x;
	ll ans = 0, count = 0;
	memset(dp, -1, sizeof(dp));
	fn(ans, count, m, n, x);
	cout << dp[0][x] << "\n";
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