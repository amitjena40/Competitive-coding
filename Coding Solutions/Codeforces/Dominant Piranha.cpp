#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	priority_queue<pair<ll, ll>> pq;

	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		pq.push({a[i], i});
	}

	ll ans = -1;

	while (!pq.empty())
	{
		ll id = pq.top().second;

		if (id >= 1 && a[id] > a[id - 1])
		{
			ans = id + 1;
			break;
		}
		else if (id < n - 1 && a[id] > a[id + 1])
		{
			ans = id + 1;
			break;
		}

		pq.pop();
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