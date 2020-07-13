#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	string s;
	cin >> s;
	unordered_map<char, ll> m;
	m['I'] = 1;
	m['V'] = 5;
	m['X'] = 10;
	m['L'] = 50;
	m['C'] = 100;
	m['D'] = 500;
	m['M'] = 1000;

	ll ans = 0;
	ll i;
	for (i = 0; i < s.size() - 1;)
	{
		if (m[s[i]] >= m[s[i + 1]])
		{
			ans += m[s[i]];
			i++;
		}
		else
		{
			ans += m[s[i + 1]] - m[s[i]];
			i += 2;
		}
	}

	if (i < s.size())
	{
		ans += m[s[i]];
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