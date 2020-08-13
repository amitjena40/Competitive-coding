#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	string s[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	bool ans = true;
	for (ll i = n - 2; i >= 0; i--)
	{
		for (ll j = n - 2; j >= 0; j--)
		{
			if (s[i][j] == '1' && !(s[i + 1][j] == '1') && !(s[i][j + 1] == '1'))
			{
				ans = false;
				break;
			}
		}
	}

	if (ans)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
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