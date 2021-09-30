#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, p;
	cin >> n >> p;

	vector<ll> arr(p + 1, 0);
	while (n--)
	{
		ll x, r;
		cin >> x >> r;

		ll minIdx = (x - r >= 0) ? x - r : 0;
		ll maxIdx = (x + r <= p) ? x + r : p;

		arr[minIdx] += 1;
		arr[maxIdx + 1] -= 1;
	}

	for (ll i = 1; i <= p; i++)
	{
		arr[i] += arr[i - 1];
	}

	for (ll i = 0; i <= p; i++)
	{
		arr[i] = (arr[i] > 1) ? 0 : arr[i];
	}

	ll ans = 0, curr = 0;
	for (ll i = 0; i <= p; i++)
	{
		if (arr[i] == 0)
		{
			curr++;
			ans = max(ans, curr);
		}
		else
		{
			curr = 0;
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
	t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}