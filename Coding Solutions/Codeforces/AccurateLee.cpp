#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	string s, ans = "";
	cin >> s;
	ll flag = 0;
	for (ll i = 0; i < n - 1; i++)
	{
		if (s[i] == '1' && s[i + 1] == '0')
		{
			flag = 1;
			break;
		}
	}

	if (flag == 0)
	{
		cout << s << "\n";
		return;
	}

	for (ll i = 0; i < n; i++)
	{
		if (s[i] == '0')
		{
			ans += "0";
		}
		else
		{
			break;
		}
	}

	ans += "0";
	for (ll i = n - 1; i >= 0; i--)
	{
		if (s[i] == '1')
		{
			ans += "1";
		}
		else
		{
			break;
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