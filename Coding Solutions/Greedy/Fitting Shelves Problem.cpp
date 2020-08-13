#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll m, n, w;
	cin >> w >> m >> n;

	ll min_space = INT_MAX, no_m, no_n;
	for (ll i = w / n; i >= 0; i--)
	{
		for (ll j = 0; j <= w / m; j++)
		{
			ll ans = w - i * n - j * m;

			if (ans < 0)
			{
				break;
			}

			if (ans < min_space)
			{
				min_space = ans;
				no_n = i;
				no_m = j;
			}

			if (min_space == 0)
			{
				break;
			}
		}

		if (min_space == 0)
		{
			break;
		}
	}

	cout << no_m << " " << no_n << " " << min_space << "\n";
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