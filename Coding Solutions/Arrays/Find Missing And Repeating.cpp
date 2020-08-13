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

	ll xorAns = 0;
	for (ll i = 0; i < n; i++)
	{
		xorAns = xorAns ^ a[i];
	}

	for (ll i = 1; i <= n; i++)
	{
		xorAns = xorAns ^ i;
	}

	ll k = (ll)(log2(xorAns));
	ll p0 = 0, p1 = 0;
	for (ll i = 0; i < n; i++)
	{
		if (a[i] & (1 << k))
		{
			p1 = p1 ^ a[i];
		}
		else
		{
			p0 = p0 ^ a[i];
		}
	}

	for (ll i = 1; i <= n; i++)
	{
		if (i & (1 << k))
		{
			p1 = p1 ^ i;
		}
		else
		{
			p0 = p0 ^ i;
		}
	}

	ll count1 = 0, count0 = 0;
	for (ll i = 0; i < n; i++)
	{
		if (a[i] == p1)
		{
			count1++;
		}
		else if (a[i] == p0)
		{
			count0++;
		}
	}

	if (count0 > 0)
	{
		cout << p0 << " " << p1 << "\n";
	}
	else
	{
		cout << p1 << " " << p0 << "\n";
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