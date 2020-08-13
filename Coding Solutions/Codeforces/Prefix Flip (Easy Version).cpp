#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	string a, b;
	cin >> a >> b;

	ll ans = 0;
	vector<ll> steps;
	for (ll i = 0; i < n; i++)
	{
		if (a[i] != b[i])
		{
			if (i == 0)
			{
				ans++;
				steps.PB(i + 1);
			}
			else
			{
				ans += 3;
				steps.PB(i + 1);
				steps.PB(1);
				steps.PB(i + 1);
			}
		}
	}

	cout << ans << " ";
	for (ll i = 0; i < steps.size(); i++)
	{
		cout << steps[i] << " ";
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