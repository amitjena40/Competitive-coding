#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	string s;
	cin >> s;
	string rev = s;
	reverse(rev.begin(), rev.end());
	string str = s + "$" + rev;
	ll lps[str.size()];
	ll index = 0;
	lps[0] = 0;
	for (ll i = 1; i < str.size();)
	{
		if (str[i] == str[index])
		{
			lps[i] = index + 1;
			index++;
			i++;
		}
		else if (index != 0)
		{
			index = lps[index - 1];
		}
		else
		{
			lps[i] = 0;
			i++;
		}
	}

	cout << s.size() - lps[str.size() - 1] << "\n";
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