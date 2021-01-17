#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll a[1000000] = {0};
	ll q = 2, len = 1;
	a[0] = 1;

	while (q <= n)
	{
		ll num = 0, x = 0;

		while (x < len)
		{
			a[x] = a[x] * q;
			a[x] += num;
			num = a[x] / 10;
			a[x] = a[x] % 10;
			x++;
		}

		while (num != 0)
		{
			a[len] = num % 10;
			num /= 10;
			len++;
		}

		q++;
	}

	len--;
	while (len >= 0)
	{
		cout << a[len];
		len--;
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
	t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}