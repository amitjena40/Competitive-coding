#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll ans = 0;
	while (n != 1)
	{
		if (n % 6 == 0)
		{
			n /= 6;
		}
		else
		{
			if ((n * 2) % 6 == 0)
			{
				n = 2 * n;
			}
			else
			{
				ans = -1;
				break;
			}
		}
		ans++;
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