#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll a[n], curr_sum = 0;;
	for (ll i = 0; i < n; i++)
	{
		ll item;
		cin >> item;
		curr_sum += item;
		a[i] = curr_sum;
	}

	ll q;
	cin >> q;
	while (q--)
	{
		ll x;
		cin >> x;
		ll lo = 0, hi = n - 1;
		ll ans = -1;
		while (lo <= hi)
		{
			ll mid = lo + (hi - lo) / 2;
			if (a[mid] == x)
			{
				ans = mid;
				break;
			}
			else if (a[mid] < x)
			{
				if (a[mid + 1] > x)
				{
					ans = mid;
					break;
				}

				lo = mid + 1;
			}
			else
			{
				hi = mid - 1;
			}
		}

		if (ans == -1)
		{
			cout << 0 << " " << x << "\n";
		}
		else
			cout << ans + 1 << " " << x - a[ans] << "\n";
	}
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