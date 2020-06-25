#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll a, b, c;
	cin >> a >> b >> c;
	ll ans1, ans2;
	if (a < c)
	{
		ans1 = 1;
	}
	else
	{
		ans1 = -1;
	}

	ll comp1, comp2;
	comp2 = c;

	comp1 = b * a;

	if (comp2 < comp1)
	{
		ans2 = b;
	}
	else
	{
		ans2 = -1;
	}

	cout << ans1 << " " << ans2 << "\n";
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