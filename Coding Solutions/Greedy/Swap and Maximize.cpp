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

	sort(a, a + n);
	ll i = 1, j = n - 2;
	while (i < j)
	{
		swap(a[i], a[j]);
		i += 2;
		j -= 2;
	}

	ll sum = 0;
	for (ll i = 0; i < n - 1; i++)
	{
		sum += abs(a[i] - a[i + 1]);
	}

	sum += abs(a[n - 1] - a[0]);
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