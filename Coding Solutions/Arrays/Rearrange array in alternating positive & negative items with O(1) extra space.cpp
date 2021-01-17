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

	ll i = 0, j = n - 1;
	while (i < j)
	{
		while (i != n && a[i] > 0)
			i++;

		while (j >= 0 && a[j] < 0)
			j--;

		if (i < j)
			swap(a[i], a[j]);
	}

	if (i == 0 || i == n)
	{
		for (ll i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}

	ll k = 0;

	while (i < n && k < n)
	{
		swap(a[i], a[k]);
		i++;
		k += 2;
	}

	for (ll i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
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