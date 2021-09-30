#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;


void solve()
{
	ll n, x;
	cin >> n >> x;
	ll n1 = n / 2, n2 = n - n1;
	vector<ll> a(n1), b(n2);
	for (ll i = 0; i < n1; i++)
	{
		cin >> a[i];
	}

	for (ll i = 0; i < n2; i++)
	{
		cin >> b[i];
	}

	vector<ll> sum1, sum2;
	for (ll i = 0; i < (1 << n1); i++)
	{
		ll curr = 0;
		for (ll j = 0; j < n1; j++)
		{
			if (i & (1 << j))
			{
				curr += a[j];
			}
		}
		sum1.push_back(curr);
	}

	for (ll i = 0; i < (1 << n2); i++)
	{
		ll curr = 0;
		for (ll j = 0; j < n2; j++)
		{
			if (i & (1 << j))
			{
				curr += b[j];
			}
		}
		sum2.push_back(curr);
	}

	sort(sum1.begin(), sum1.end());
	sort(sum2.begin(), sum2.end());

	ll ans = 0;
	for (ll s1 : sum1)
	{
		ans += upper_bound(sum2.begin(), sum2.end(), x - s1) - lower_bound(sum2.begin(), sum2.end(), x - s1);
	}

	cout << ans;
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