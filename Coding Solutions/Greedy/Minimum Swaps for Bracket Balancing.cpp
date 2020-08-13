#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, count = 0, sum = 0, p = 0;
	cin >> n;
	string s;
	cin >> s;
	vector<ll> pos;

	for (ll i = 0; i < s.size(); i++)
	{
		if (s[i] == '[')
		{
			pos.PB(i);
		}
	}

	for (ll i = 0; i < s.size(); i++)
	{
		if (s[i] == '[')
		{
			count++;
			p++;
		}
		else
		{
			count--;
		}

		if (count < 0)
		{
			sum += pos[p] - i;
			swap(s[i], s[pos[p]]);
			count = 1;
			p++;
		}
	}

	cout << sum << "\n";
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