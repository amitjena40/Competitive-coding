#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

ll sd(ll n)
{
	ll sum = 0;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}

	return sum;
}


void solve()
{
	ll n, s;
	cin >> n >> s;
	ll ans = 0;
	if (sd(n) <= s)
	{
		ans = 0;
	}
	else
	{
		ll pw = 1;
		for (ll i = 0; i < 18; i++)
		{
			ll dig = (n / pw) % 10;
			ll req = pw * ((10 - dig) % 10);
			n += req;
			ans += req;
			if (sd(n) <= s)
			{
				break;
			}
			pw *= 10;
		}
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