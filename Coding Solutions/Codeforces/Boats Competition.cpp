#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll w[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> w[i];
	}

	sort(w, w + n);
	ll max_team = 0;
	for (ll sum = w[0] + w[1]; sum <= w[n - 1] + w[n - 2]; sum++)
	{
		ll count = 0;
		ll start = 0, end = n - 1;
		while (start < end)
		{
			if (w[start] + w[end] == sum)
			{
				count++;
				start++;
				end--;
			}
			else if (w[start] + w[end] < sum)
			{
				start++;
			}
			else
			{
				end--;
			}
		}
		max_team = max(max_team, count);
	}

	cout << max_team << "\n";
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