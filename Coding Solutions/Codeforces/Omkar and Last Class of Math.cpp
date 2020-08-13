#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	if (n % 2 == 0)
	{
		cout << n / 2 << " " << n / 2;
	}
	else
	{
		ll maxPrime = 1;
		ll num = n;
		for (ll i = 3; i <= sqrt(n); i += 2) {
			while (n % i == 0) {
				maxPrime = max(max(i, n / i), maxPrime);
				n = n / i;
			}
		}

		cout << maxPrime << " " << num - maxPrime;
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