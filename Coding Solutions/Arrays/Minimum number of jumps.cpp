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

	if (a[0] == 0)
	{
		cout << "-1\n";
		return;
	}

	ll jumps = 1, steps = a[0], ladder = a[0], maxReach = a[0];

	for (ll i = 1; i < n; i++)
	{
		if (i == n - 1)
		{
			cout << jumps << "\n";
			return;
		}

		maxReach = max(maxReach, i + a[i]);

		if (a[i] + i > ladder)
		{
			ladder = a[i] + i;
		}

		steps--;

		if (steps == 0)
		{
			jumps++;

			if (i >= maxReach)
			{
				cout << "-1\n";
				return;
			}

			steps = ladder - i;
		}
	}

	//cout << jumps << "\n";
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