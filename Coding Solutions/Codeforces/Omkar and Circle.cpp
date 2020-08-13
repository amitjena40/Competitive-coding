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

	ll prefix[n], suffix[n];
	for (ll i = 0; i < n; i++)
	{
		prefix[i] = a[i];
		if (i >= 2)
		{
			prefix[i] += prefix[i - 2];
		}
	}

	for (ll i = n - 1; i >= 0; i--)
	{
		suffix[i] = a[i];
		if (i < n - 2)
		{
			suffix[i] += suffix[i + 2];
		}
	}

	ll ans = 0;
	if (n > 1)
	{
		for (ll i = 1; i < n; i++)
		{
			ans = max(ans, prefix[i - 1] + suffix[i]);
		}
		ans = max(ans, prefix[n - 1]);
	}
	else
	{
		ans = a[0];
	}

	cout << ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//ll t;
	//cin >> t;
	//while (t--)
	//{
	solve();
	//}
	return 0;
}