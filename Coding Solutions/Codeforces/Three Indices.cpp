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
	vector<ll> ans;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (ll i = 1; i < n - 1; i++)
	{
		if (a[i] > a[i - 1])
		{
			for (ll j = i + 1; j < n; j++)
			{
				if (a[j] < a[i])
				{
					ans = {i, i + 1, j + 1};
					break;
				}
			}
		}
	}

	if (ans.size() == 0)
	{
		cout << "NO\n";
	}
	else
	{
		cout << "YES\n";
		for (ll i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << " ";
		}
		cout << "\n";
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