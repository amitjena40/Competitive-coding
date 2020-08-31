#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	string s;
	cin >> s;
	unordered_set<char> m;
	for (auto x : s)
	{
		m.insert(x);
	}

	ll maxCount = m.size();
	vector<ll> v(256, 0);
	ll ans = INT_MAX, count = 0;
	ll i = 0, j = 0;
	while (j < s.size())
	{
		if (v[s[j]] == 0)
		{
			count++;
		}
		v[s[j]]++;
		if (count == maxCount)
		{
			while (v[s[i]] > 1)
			{
				v[s[i]]--;
				i++;
			}
			ans = min(ans, j - i + 1);
		}
		j++;
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