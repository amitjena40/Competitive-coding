#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

void solve()
{
	ll n, x, y;
	cin >> n >> x >> y;
	bool dp[1001];
	memset(dp, 0, sizeof(dp));
	for (ll i = 0; i <= n; i++)
	{
		if (!dp[i])
		{
			if (i + 1 <= n)
			{
				dp[i + 1] = true;
			}

			if (i + x <= n)
			{
				dp[i + x] = true;
			}

			if (i + y <= n)
			{
				dp[i + y] = true;
			}
		}
	}

	if (dp[n])
	{
		cout << "A" << "\n";
	}
	else
	{
		cout << "B" << "\n";
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