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
	bool poss = true;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);
	for (ll i = 1; i < n; i++)
	{
		if (abs(a[i] - a[i - 1]) > 1)
		{
			poss = false;
			break;
		}
	}

	if (poss)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
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