#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	if (n == 0)
	{
		cout << "0\n";
		return;
	}

	if (n == 1)
	{
		cout << a[0] << "\n";
		return;
	}

	if (n == 2)
	{
		cout << max(a[0], a[1]) << "\n";
		return;
	}

	ll dp[n];
	dp[0] = a[0];
	dp[1] = max(a[1], a[0]);

	for (ll i = 2; i < n; i++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
	}

	cout << dp[n - 1] << "\n";
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