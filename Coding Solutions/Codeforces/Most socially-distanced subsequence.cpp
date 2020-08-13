#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll p[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> p[i];
	}

	vector<ll> ans;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		if (i == 0 || i == n - 1 || (p[i - 1] < p[i] != p[i] < p[i + 1]))
		{
			ans.PB(p[i]);
		}
	}

	cout << ans.size() << "\n";
	for (auto x : ans)
	{
		cout << x << " ";
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
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}