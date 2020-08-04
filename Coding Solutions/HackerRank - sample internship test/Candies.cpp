#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll a[n], left[n], right[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		left[i] = 1;
		right[i] = 1;
	}

	for (ll i = 1; i < n; i++)
	{
		if (a[i] > a[i - 1])
		{
			left[i] = left[i - 1] + 1;
		}
	}

	for (ll i = n - 2; i >= 0; i--)
	{
		if (a[i] > a[i + 1])
		{
			right[i] = right[i + 1] + 1;
		}
	}

	ll sum = 0;
	for (ll i = 0; i < n; i++)
	{
		sum += max(left[i], right[i]);
	}


	cout << sum;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//ll t;
	//cin >> t;
	//while (t--)
	//{
	solve();
	//}
	return 0;
}