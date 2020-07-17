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

	ll ans = 0;
	if (a[n - 2] < a[n - 1])
	{
		for (ll i = n - 3; i >= 0; i--)
		{
			if (a[i] > a[i + 1])
			{
				ans = i + 1;
				break;
			}
		}
	}
	else
	{
		ll i;
		for (i = n - 3; i >= 0; i--)
		{
			if (a[i] < a[i + 1])
			{
				break;
			}
		}

		for (i = i - 1; i >= 0; i--)
		{
			if (a[i] > a[i + 1])
			{
				ans = i + 1;
				break;
			}
		}
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