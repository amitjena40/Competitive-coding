#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

struct items
{
	ll a, b;
};

void solve()
{
	ll n;
	cin >> n;
	items item[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> item[i].a;
	}

	set<ll> s;
	for (ll i = 0; i < n; i++)
	{
		cin >> item[i].b;
		s.insert(item[i].b);
	}

	string ans = "Yes\n";
	if (s.size() == 1)
	{
		for (ll i = 0; i < n - 1; i++)
		{
			if (item[i].a > item[i + 1].a)
			{
				ans = "No\n";
				break;
			}
		}
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
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}