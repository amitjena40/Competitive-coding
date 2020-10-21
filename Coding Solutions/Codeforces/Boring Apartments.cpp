#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

ll countD(ll num)
{
	ll ans = 0;
	while (num > 0)
	{
		num /= 10;
		ans++;
	}

	return ans;
}

void solve()
{
	ll x;
	cin >> x;
	ll d = countD(x);
	ll ans = (x != 1) ? 10 * (x / (ll)pow(10, d - 1) - 1) : 0;
	if (d == 1)
	{
		ans += 1;
	}
	else if (d == 2)
	{
		ans += 3;
	}
	else if (d == 3)
	{
		ans += 6;
	}
	else
	{
		ans += 10;
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