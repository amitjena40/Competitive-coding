#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	string ans = "";
	ll count8 = (n / 4) + 1;
	if (n % 4 == 0)
	{
		count8 = (n - 1) / 4 + 1;
	}

	for (ll i = 0; i < n - count8; i++)
	{
		ans += "9";
	}

	while (count8--)
	{
		ans += "8";
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