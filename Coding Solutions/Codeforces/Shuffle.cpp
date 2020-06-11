#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, x, m;
	cin >> n >> x >> m;
	ll l, r, l1 = x, r1 = x;
	while (m--)
	{
		cin >> l >> r;
		if ((l <= l1 && r >= l1) || (l <= r1 && r >= r1) || (l <= l1 && r >= r1) || (l1 <= l && r1 >= r))
		{
			l1 = min(l, l1);
			r1 = max(r, r1);
		}
	}
	cout << r1 - l1 + 1 << "\n";
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