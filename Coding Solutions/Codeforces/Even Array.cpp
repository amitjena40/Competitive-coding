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
	ll nodd = 0, neven = 0, mismatch = 0;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] % 2 == 0)
		{
			neven++;
		}
		else
		{
			nodd++;
		}

		if (a[i] % 2 != i % 2)
		{
			mismatch++;
		}
	}

	if (n % 2 != 0)
	{
		ll codd = n / 2;
		ll ceven = (n + 1) / 2;
		if (nodd != codd || neven != ceven)
		{
			cout << "-1\n";
		}
		else
		{
			cout << mismatch / 2 << "\n";
		}
	}
	else
	{
		ll codd = n / 2;
		ll ceven = n / 2;
		if (nodd != codd || neven != ceven)
		{
			cout << "-1\n";
		}
		else
		{
			cout << mismatch / 2 << "\n";
		}
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