#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

void solve()
{
	ll n, k, ans;
	cin >> n >> k;
	if (k >= n)
	{
		ans = 1;
	}
	else
	{
		ans = INT_MAX;
		for (ll i = 1; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				if (i <= k)
				{
					ans = min(ans, (n / i));
				}

				if ((n / i) <= k)
				{
					ans = min(ans, i);
				}
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