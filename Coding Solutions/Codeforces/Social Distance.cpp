#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, k;
	string s;
	cin >> n >> k >> s;

	ll ans = 0;
	set<ll> st;
	for (ll i = 0; i < n; i++)
	{
		if (s[i] == '1')
		{
			st.insert(i);
		}
	}

	for (ll i = 0; i < n; i++)
	{
		if (s[i] == '0')
		{
			auto it = st.lower_bound(i - k);
			if (it == st.end() or * it > i + k)
			{
				ans++;
				s[i] = '1';
				st.insert(i);
			}
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