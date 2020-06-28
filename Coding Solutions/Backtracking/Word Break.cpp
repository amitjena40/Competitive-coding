#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void wordBreak(string s, ll n, string result, unordered_set<string> d)
{
	for (ll i = 1; i <= n; i++)
	{
		string prefix = s.substr(0, i);
		if (d.find(prefix) != d.end())
		{
			if (i == n)
			{
				result += prefix;
				result += ")";
				cout << result;
				return;
			}
			wordBreak(s.substr(i, n - i), n - i, result + prefix + " ", d);
		}
	}
}

void solve()
{
	ll n;
	cin >> n;
	string dict[n];
	unordered_set<string> d;
	for (ll i = 0; i < n; i++)
	{
		cin >> dict[i];
		d.insert(dict[i]);
	}

	string s;
	cin >> s;
	wordBreak(s, s.size(), "(", d);
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