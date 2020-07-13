#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	string a[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);

	ll num = min(a[0].size(), a[n - 1].size());
	string ans = "";
	for (ll i = 0; i < num; i++)
	{
		if (a[0][i] != a[n - 1][i])
		{
			break;
		}
		ans.PB(a[0][i]);
	}
	if (ans.size() > 0)
		cout << ans << "\n";
	else
		cout << "-1\n";
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