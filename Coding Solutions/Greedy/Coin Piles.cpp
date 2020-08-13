#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, k;
	cin >> n >> k;
	ll a[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);
	ll ans = INT_MAX, cum = 0, temp = 0;
	for (ll i = 0; i < n; i++)
	{
		temp = cum;
		cum += a[i];
		for (ll j = n - 1; j > i; j--)
		{
			if (a[j] - a[i] > k)
			{
				temp += a[j] - a[i] - k;
			}
		}
		ans = min(ans, temp);
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