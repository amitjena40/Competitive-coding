#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	string ans;
	if (n == 1)
	{
		ans = "FastestFinger";
	}
	else if (n == 2)
	{
		ans = "Ashishgup";
	}
	else if (n % 2 != 0)
	{
		ans = "Ashishgup";
	}
	else
	{
		ll podd = 0, peven = 0;
		for (ll i = 2; i * i <= n; i++)
		{
			while (n % i == 0)
			{
				n /= i;
				if (i == 2)
				{
					peven++;
				}
				else
				{
					podd++;
				}
			}

			if (n == 1)
			{
				break;
			}
		}

		if (n > 1 && n % 2 != 0)
		{
			podd++;
		}

		if (peven == 1 && podd == 1)
		{
			ans = "FastestFinger";
		}
		else if (peven == 2 && podd == 1)
		{
			ans = "Ashishgup";
		}
		else if (peven >= 2 && podd == 0)
		{
			ans = "FastestFinger";
		}
		else
		{
			ans = "Ashishgup";
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