#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	string s;
	cin >> s;

	stack<ll> s0, s1;
	ll group = 0;
	ll ans[n];
	for (ll i = 0; i < n; i++)
	{
		if (s[i] == '0')
		{
			if (s1.empty())
			{
				group++;
				ans[i] = group;
				s0.push(group);
			}
			else
			{
				ll temp = s1.top();
				s1.pop();
				ans[i] = temp;
				s0.push(temp);
			}
		}
		else
		{
			if (s0.empty())
			{
				group++;
				ans[i] = group;
				s1.push(group);
			}
			else
			{
				ll temp = s0.top();
				s0.pop();
				ans[i] = temp;
				s1.push(temp);
			}
		}
	}

	cout << group << "\n";
	for (ll i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	cout << "\n";
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