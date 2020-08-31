#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	string s;
	cin >> s;
	ll n = s.size();

	unordered_map<char, ll> m;
	ll i = 0, j = 0, ans = 0;
	while (i < n)
	{
		if (j < n and m[s[j]] == 0)
		{
			m[s[j]]++;
			ans += j - i + 1;
			j++;
		}
		else
		{
			m[s[i]]--;
			i++;
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