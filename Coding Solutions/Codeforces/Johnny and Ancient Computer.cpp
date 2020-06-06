#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll a, b;
	cin >> a >> b;

	ll a2 = 0, b2 = 0;
	while (a % 2 == 0)
	{
		a /= 2;
		a2++;
	}

	while (b % 2 == 0)
	{
		b /= 2;
		b2++;
	}

	ll ans;
	if (a == b)
	{
		ll rem = abs(a2 - b2);
		ll step = 0;
		while (rem != 0)
		{
			if (rem >= 3)
			{
				rem -= 3;
			}
			else if (rem >= 2)
			{
				rem -= 2;
			}
			else
			{
				rem -= 1;
			}
			step++;
		}
		ans = step;
	}
	else
	{
		ans = -1;
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