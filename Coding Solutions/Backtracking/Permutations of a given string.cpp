#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void fn(map<char, ll> m, string result, ll level)
{
	if (level == m.size())
	{
		cout << result << " ";
		return;
	}

	for (auto it = m.begin(); it != m.end(); ++it)
	{
		if (it->second == 0)
		{
			continue;
		}

		result[level] = it->first;
		it->second--;
		fn(m, result, level + 1);
		it->second++;
	}
}

void solve()
{
	string s;
	cin >> s;
	string result = s;
	map<char, ll> m;
	for (ll i = 0; i < s.size(); i++)
	{
		m[s[i]]++;
	}

	fn(m, result, 0);
	cout << "\n";
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