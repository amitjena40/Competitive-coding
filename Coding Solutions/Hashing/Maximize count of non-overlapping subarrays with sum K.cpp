#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, k;
	cin >> n >> k;
	ll a[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	unordered_set<ll> pSum;
	pSum.insert(0);
	ll curr_sum = 0, ans = 0;
	for (auto x : a)
	{
		curr_sum += x;
		if (pSum.find(curr_sum - k) != pSum.end())
		{
			ans++;
			curr_sum = 0;
			pSum.clear();
			pSum.insert(0);
		}

		pSum.insert(curr_sum);
	}

	cout << ans << "\n";
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