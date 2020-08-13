#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll a[n], sum = 0;
	vector<ll> odd, even;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
		if (a[i] % 2 == 0)
		{
			even.PB(a[i]);
		}
		else
		{
			odd.PB(a[i]);
		}
	}

	string ans;
	if (sum % 2 == 0)
	{
		ans = "YES";
	}
	else
	{
		ll flag = 0;
		for (ll i = 0; i < odd.size(); i++)
		{
			auto it1 = find(even.begin(), even.end(), odd[i] - 1);
			auto it2 = find(even.begin(), even.end(), odd[i] + 1);
			if (it1 != even.end() || it2 != even.end())
			{
				flag = 1;
				break;
			}
		}

		if (flag)
		{
			ans = "YES";
		}
		else
		{
			ans = "NO";
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
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}