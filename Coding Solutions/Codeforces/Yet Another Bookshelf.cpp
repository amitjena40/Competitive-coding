#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll a[n], first = -1, last = -1;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == 1)
		{
			if (first == -1)
			{
				first = i;
			}

			last = i;
		}
	}

	ll count = 0;
	for (ll i = first; i <= last; i++)
	{
		if (a[i] == 0)
		{
			count++;
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