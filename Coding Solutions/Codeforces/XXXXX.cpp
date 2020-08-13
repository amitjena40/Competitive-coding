#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, x;
	cin >> n >> x;
	ll a[n], curr_sum = 0;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	ll max_len = 0, count = 0, min_index = -1;
	for (ll i = 0; i < n; i++)
	{
		curr_sum  = (curr_sum + a[i] % x) % x;

		if (curr_sum != 0)
		{
			max_len = (i + 1);
			if (min_index == -1)
			{
				min_index = i;
			}
		}
		else
		{
			if (max_len < (i - min_index) && min_index != -1)
			{
				max_len = i - min_index;
			}
		}
	}

	if (max_len == 0)
	{
		cout << "-1\n";
	}
	else
	{
		cout << max_len << "\n";
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
	ll t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}