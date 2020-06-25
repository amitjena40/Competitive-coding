#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	string s;
	cin >> s;
	ll score = 0, min_num = 0;
	vector<ll> idx;
	for (ll i = 0; i < s.size(); i++)
	{
		if (s[i] == '-')
		{
			score--;
		}
		else
		{
			score++;
		}

		if (score < 0 )
		{
			if (score < min_num)
			{
				idx.PB(i + 1);
				min_num = score;
			}

		}
	}

	ll ans = s.size();
	for (ll i = 0; i < idx.size(); i++)
	{
		ans += idx[i];
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