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
	vector<ll> ans;
	bool flip = false;
	ll pos1 = 0, pos2 = n - 1;
	for (ll i = n - 1; i >= 0; i--)
	{
		if (!flip)
		{
			if (b[i] == a[pos1])
			{
				ans.PB(1);
			}
			ans.PB(i + 1);
			pos1++;
			flip = true;
		}
		else
		{
			if (b[i] != a[pos2])
			{
				ans.PB(1);
			}
			ans.PB(i + 1);
			pos2--;
			flip = false;
		}
	}

	cout << ans.size() << " ";
	for (ll i = 0; i < ans.size(); i++)
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