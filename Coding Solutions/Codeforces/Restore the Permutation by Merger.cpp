#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll a[2 * n];
	unordered_map<ll, ll> m;
	for (ll i = 0; i < 2 * n; i++)
	{
		cin >> a[i];
		if (m[a[i]] == 0)
		{
			cout << a[i] << " ";
			m[a[i]] = 1;
		}
	}
	cout << "\n";
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