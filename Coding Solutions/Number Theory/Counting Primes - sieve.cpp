#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

vector<ll> isPrime(10000001, 1);

void primeSieve()
{
	isPrime[0] = 0;
	isPrime[1] = 0;
	for (ll i = 2; i * i <= 10000000; i++)
	{
		if (isPrime[i] != 1)
			continue;
		for (ll j = 2 * i; j <= 10000000; j += i)
		{
			isPrime[j] = 0;
		}
	}

	for (ll i = 1; i <= 10000000; i++)
	{
		isPrime[i] += isPrime[i - 1];
	}
}

void solve()
{
	ll m, n;
	cin >> m >> n;

	cout << isPrime[n] - isPrime[m - 1] << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	primeSieve();
	ll t;
	t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}