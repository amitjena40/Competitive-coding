#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	vector<ll> odd, even;
	for (ll i = 1; i <= 2 * n; i++)
	{
		ll item;
		cin >> item;
		if (item % 2 == 0)
		{
			even.PB(i);
		}
		else
		{
			odd.PB(i);
		}
	}

	ll count = n - 1;
	if (even.size() >= 2)
	{
		for (ll i = 0; i < (even.size() - 1) && count > 0; i += 2)
		{
			cout << even[i] << " " << even[i + 1] << "\n";
			count -= 1;
		}
	}

	if (odd.size() >= 2)
	{
		for (ll i = 0; i < (odd.size() - 1) && count > 0; i += 2)
		{
			cout << odd[i] << " " << odd[i + 1] << "\n";
			count -= 1;
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