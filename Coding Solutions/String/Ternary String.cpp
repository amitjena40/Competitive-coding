#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	string s;
	cin >> s;
	ll j = 0, ans = INT_MAX;
	vector<ll> count(4, 0);
	for (ll i = 0; i < s.size(); i++)
	{
		count[s[i] - '0']++;
		while (count[1] > 0 && count[2] > 0 && count[3] > 0)
		{
			ans = min(ans, i - j + 1);
			count[s[j] - '0']--;
			j++;
		}
	}

	if (ans == INT_MAX)
	{
		ans = 0;
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
	t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}