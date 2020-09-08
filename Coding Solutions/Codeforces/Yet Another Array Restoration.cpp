#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, x, y;
	cin >> n >> x >> y;

	for (ll i = 1; i <= (y - x); i++)
	{
		if ((y - x) % i != 0)
			continue;

		bool xpresent = false;
		vector<ll> ans;
		for (ll j = y; j >= 1 && ans.size() < n; j -= i)
		{
			ans.PB(j);
			if (j == x)
			{
				xpresent = true;
			}
		}

		if (xpresent)
		{
			ll count = 1;
			while (ans.size() != n)
			{
				ans.PB(y + count * i);
				count++;
			}

			for (auto x : ans)
			{
				cout << x << " ";
			}
			cout << "\n";
			return;
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