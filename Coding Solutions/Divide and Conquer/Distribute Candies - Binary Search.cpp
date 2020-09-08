#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

bool check(ll a[], ll n, ll k, ll pos)
{
	ll count = 0;
	for (ll i = 0; i < n; i++)
	{
		count += a[i] / pos;
		if (count >= k)
			return true;
	}

	return false;
}

void solve()
{
	ll n, k;
	cin >> n >> k;
	ll a[n], lo, hi;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);
	lo = 1, hi = a[n - 1];
	ll ans = 0;
	while (lo <= hi)
	{
		ll mid = lo + (hi - lo) / 2;
		if (check(a, n, k, mid))
		{
			lo = mid + 1;
			ans = mid;
		}
		else
		{
			hi = mid - 1;
		}
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