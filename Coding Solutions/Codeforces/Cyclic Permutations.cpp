#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll fact[n + 1];
	fact[0] = 1; fact[1] = 1;
	ll ans = 0, pow2 = 1;
	for (ll i = 2; i <= n; i++)
	{
		fact[i] = ((i % mod) * (fact[i - 1] % mod)) % mod;
		pow2 = ((pow2 % mod) * (2 % mod)) % mod;
	}

	cout << (fact[n]  - pow2 + mod) % mod;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	/*ll t;
	cin >> t;
	while (t--)
	{
		solve();
	}*/
	solve();
	return 0;
}