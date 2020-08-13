#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll a[n], reqa = INT_MAX, b[n], reqb = INT_MAX;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		reqa = min(reqa, a[i]);
	}

	for (ll i = 0; i < n; i++)
	{
		cin >> b[i];
		reqb = min(reqb, b[i]);
	}

	ll count = 0;
	for (ll i = 0; i < n; i++)
	{
		if (a[i] == reqa && b[i] != reqb)
		{
			count += b[i] - reqb;
		}
		else if (a[i] != reqa && b[i] == reqb)
		{
			count += a[i] - reqa;
		}
		else if (a[i] != reqa && b[i] != reqb)
		{
			count += max(b[i] - reqb, a[i] - reqa);
		}
	}

	cout << count << "\n";
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