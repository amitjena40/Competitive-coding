#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll s[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	sort(s, s + n);
	ll ans = INT_MAX;
	for (ll i = 0; i < n - 1; i++)
	{
		if (ans > abs(s[i] - s[i + 1]))
		{
			ans = abs(s[i] - s[i + 1]);
		}
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