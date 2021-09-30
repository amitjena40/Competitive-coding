#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

ll minMerge(ll lo, ll hi, ll a[])
{
	if (lo >= hi)
		return 0;

	if (a[lo] == a[hi])
	{
		return minMerge(lo + 1, hi - 1, a);
	}
	else if (a[lo] > a[hi])
	{
		a[hi - 1] += a[hi];
		return 1 + minMerge(lo, hi - 1, a);
	}
	else
	{
		a[lo + 1] += a[lo];
		return 1 + minMerge(lo + 1, hi, a);
	}
}

void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << minMerge(0, n - 1, a) << "\n";
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
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}