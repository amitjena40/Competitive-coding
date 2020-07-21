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
	bool greater1 = false;
	ll idx = -1;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		if (idx == -1 && a[i] > 1)
		{
			greater1 = true;
			idx = i + 1;
		}
	}

	if (greater1)
	{
		if (idx % 2 != 0)
		{
			cout << "First\n";
		}
		else
		{
			cout << "Second\n";
		}
	}
	else
	{
		if (n % 2 != 0)
		{
			cout << "First\n";
		}
		else
		{
			cout << "Second\n";
		}
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