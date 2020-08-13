#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	string s, ans;
	cin >> s;
	ll count0 = 0, count1 = 0;
	for (ll i = 0; i < s.size(); i++)
	{
		if (s[i] == '0')
		{
			count0++;
		}
		else
		{
			count1++;
		}
	}

	if (count0 == 0 || count1 == 0)
	{
		ans = "NET";
	}
	else
	{
		if (min(count0, count1) % 2 != 0)
		{
			ans = "DA";
		}
		else
		{
			ans = "NET";
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