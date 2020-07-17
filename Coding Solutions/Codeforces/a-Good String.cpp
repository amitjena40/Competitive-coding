#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

ll fn(string s, char ch)
{
	if (s.size() == 1)
	{
		if (s[0] == ch)
		{
			return (ll)0;
		}
		else
		{
			return (ll)1;
		}
	}

	ll countl = 0, countr = 0;
	ll i = 0;
	for (; i < s.size() / 2; i++)
	{
		if (s[i] != ch)
		{
			countl++;
		}
	}

	for (; i < s.size(); i++)
	{
		if (s[i] != ch)
		{
			countr++;
		}
	}

	return min(countl + fn(s.substr(s.size() / 2, s.size() / 2), ch + 1), countr + fn(s.substr(0, s.size() / 2), ch + 1));
}

void solve()
{
	ll n;
	cin >> n;
	string s;
	cin >> s;
	cout << fn(s, 'a') << "\n";
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