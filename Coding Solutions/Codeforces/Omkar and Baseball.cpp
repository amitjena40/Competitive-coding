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

	ll start = 0, end = n - 1, ans = 0;
	for (; start < n; start++)
	{
		if (a[start] != start + 1)
		{
			break;
		}
	}

	for (; end >= 0; end--)
	{
		if (a[end] != end + 1)
		{
			break;
		}
	}

	if (start < end)
	{
		ll count = 0;
		for (ll i = start; i <= end; i++)
		{
			if (a[i] == (i + 1))
			{
				count++;
				break;
			}
		}
		ans = count + 1;
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