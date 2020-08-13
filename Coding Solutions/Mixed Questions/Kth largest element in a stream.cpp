#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll k, n;
	cin >> k >> n;
	priority_queue <ll, vector<ll>, greater<ll>> mn;
	for (ll i = 1; i <= n; i++)
	{
		ll item;
		cin >> item;
		ll ans;
		if (mn.size() < k)
		{
			mn.push(item);
			if (mn.size() == k)
			{
				ans = mn.top();
			}
			else
			{
				ans = -1;
			}
		}
		else
		{
			if (item < mn.top())
			{
				ans = mn.top();
			}
			else
			{
				mn.pop();
				mn.push(item);
				ans = mn.top();
			}
		}

		cout << ans << " ";
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