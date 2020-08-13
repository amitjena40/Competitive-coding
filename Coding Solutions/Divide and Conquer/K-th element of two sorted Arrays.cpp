#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

ll findKth(ll *a, ll *b, ll n, ll m, ll k)
{
	if (n > m)
	{
		return findKth(b, a, m, n, k);
	}

	if (n == 0 and m > 0)
	{
		return b[k - 1];
	}

	if (k == 1)
	{
		return min(a[0], b[0]);
	}

	ll i = min(n, k / 2), j = min(m, k / 2);

	if (a[i - 1] < b[j - 1])
	{
		return findKth(a + i, b, n - i, m, k - i);
	}
	else
	{
		return findKth(a, b + j, n, m - j, k - j);
	}
}

void solve()
{
	ll n, m, k;
	cin >> n >> m >> k;
	ll *a = new ll[n]();
	ll *b = new ll[m]();

	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (ll i = 0; i < m; i++)
	{
		cin >> b[i];
	}

	cout << findKth(a, b, n, m, k) << "\n";
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