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

	vector<ll> ans;
	ans.PB(a[0]);
	for (ll i = 1; i < n; i++)
	{
		if (a[i] > ans[ans.size() - 1])
		{
			ans.PB(a[i]);
		}
		else
		{
			auto it = lower_bound(ans.begin(), ans.end(), a[i]);
			*it = a[i];
		}
	}

	cout << ans.size();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	/*ll t;
	cin >> t;
	while (t--)
	{
	    solve();
	}*/
	solve();
	return 0;
}