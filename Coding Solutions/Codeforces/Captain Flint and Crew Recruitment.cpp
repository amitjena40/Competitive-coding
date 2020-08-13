#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	if (n >= 31)
	{
		cout << "YES\n";
		ll rem = n - 30;
		if (rem == 6 || rem == 10 || rem == 14)
		{
			if (rem == 6)
			{
				cout << "6 14 15 1\n";
			}
			else if (rem == 10)
			{
				cout << "6 10 15 9\n";
			}
			else
			{
				cout << "6 10 15 13\n";
			}
		}
		else
			cout << "6 10 14 " << n - 30 << "\n";
	}
	else
	{
		cout << "NO\n";
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