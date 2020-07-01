#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll a, b, n, m;
	cin >> a >> b >> n >> m;
	string ans;
	if ((a + b) < (n + m))
	{
		ans = "No";
	}
	else if (min(a, b) < m)
	{
		ans = "No";
	}
	else
	{
		ans = "Yes";
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