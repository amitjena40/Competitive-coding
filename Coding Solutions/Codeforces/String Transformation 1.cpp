#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		if (a[i] > b[i])
		{
			cout << "-1\n";
			return;
		}
	}

	for (char ch = 'a'; ch <= 't'; ch++)
	{
		vector<ll> idx;
		char minch = 't';
		for (ll i = 0; i < n; i++)
		{
			if (a[i] != b[i] && a[i] == ch)
			{
				idx.PB(i);
				minch = min(minch, b[i]);
			}
		}

		if (idx.size() > 0)
		{
			ans++;
		}

		for (auto x : idx)
		{
			a[x] = minch;
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