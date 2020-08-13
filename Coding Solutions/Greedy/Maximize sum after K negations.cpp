#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, k, sum = 0, neg = 0;
	cin >> n >> k;
	ll a[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] < 0)
		{
			neg++;
		}
		sum += a[i];
	}

	sort(a, a + n);
	ll idx = 0;
	while (neg != 0)
	{
		sum -= a[idx];
		a[idx] = -1 * a[idx];
		sum += a[idx];
		neg--;
		idx++;
		k--;
		if (k == 0)
		{
			break;
		}
	}
	sort(a, a + n);
	while (k > 0)
	{
		sum -= a[0];
		a[0] = -1 * a[0];
		sum += a[0];
		k--;
	}

	cout << sum << "\n";
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