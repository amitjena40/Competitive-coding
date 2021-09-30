#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll a1[n], a2[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a1[i];
	}

	for (ll i = 0; i < n; i++)
	{
		cin >> a2[i];
	}

	ll l1, l2, h1, h2;
	l1 = l2 = 0;
	h1 = h2 = n - 1;

	while (l1 + 1 != h1 && l2 + 1 != h2)
	{
		ll mid1 = l1 + (h1 - l1) / 2;
		ll mid2 = l2 + (h2 - l2) / 2;

		if (a1[mid1] == a2[mid2])
		{
			cout << a1[mid1] << "\n";
			return;
		}
		else if (a1[mid1] > a2[mid2])
		{
			h1 = mid1;
			l2 = mid2;
		}
		else
		{
			l1 = mid1;
			h2 = mid2;
		}
	}

	cout << (max(a1[l1], a2[l2]) + min(a1[h1], a2[h2])) / 2.0 << "\n";
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
	t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}