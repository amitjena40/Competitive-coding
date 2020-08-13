#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, k;
	cin >> n >> k;
	ll ans;
	if (k % n == 0)
	{
		ans = 0;
	}
	else
	{
		ans = 2;
	}

	ll a[n][n];
	memset(a, 0, sizeof(a));
	ll count = 0;
	for (ll i = 0; i < n and count < k; i++)
	{
		ll x = i, y = 0;
		for (ll j = 0; j < n and count < k; j++, count++)
		{
			a[x][y] = 1;
			x = (x + 1) % n;
			y = (y + 1) % n;
		}
	}

	cout << ans << "\n";
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			cout << a[i][j];
		}
		cout << "\n";
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