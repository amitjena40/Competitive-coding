#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	string s(51, 'a');
	cout << s << "\n";
	for (ll i = 0; i < n; i++)
	{
		ll temp;
		cin >> temp;
		if (s[temp] == 'a')
		{
			s[temp] = 'b';
		}
		else
		{
			s[temp] = 'a';
		}

		cout << s << "\n";
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