#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	string s1, s2;
	cin >> s1 >> s2;

	if (s1.size() != s2.size())
	{
		cout << "NO\n";
		return;
	}

	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	for (ll i = 0; i < s1.size(); i++)
	{
		if (s1[i] != s2[i])
		{
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
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