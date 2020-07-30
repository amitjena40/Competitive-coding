#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	string s;
	cin >> s;
	ll n = s.size();
	vector<ll> freq(10);
	ll maxF = INT_MIN;
	for (ll i = 0; i < n; i++)
	{
		freq[s[i] - '0']++;
		maxF = max(maxF, freq[s[i] - '0']);
	}

	ll ans = n - maxF;

	maxF = INT_MIN;
	for (ll i = 0; i < 10; i++)
	{
		for (ll j = 0; j < 10; j++)
		{
			ll cnt = 0;
			bool p = true;

			for (ll k = 0; k < n; k++)
			{
				if (p && s[k] - '0' == i)
				{
					cnt++;
					p = false;
				}
				else if (!p && s[k] - '0' == j)
				{
					cnt++;
					p = true;
				}
			}

			if (cnt % 2 != 0)
			{
				cnt--;
			}

			maxF = max(maxF, cnt);
		}
	}

	ans = min(ans, n - maxF);
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