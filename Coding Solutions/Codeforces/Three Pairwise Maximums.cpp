#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll x, y, z;
	cin >> x >> y >> z;
	if ((x == y && y == max(y, z)) || (y == z && y == max(x, y)) || (x == z && z == max(y, z)))
	{
		cout << "YES\n";
		cout << max(x, max(y, z)) << " " << min(x, min(y, z)) << " " << max((min(x, min(y, z)) - 1), (ll)1) << "\n";
	}
	else
	{
		cout << "NO\n";
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