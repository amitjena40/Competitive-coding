#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	string b, a = "";
	cin >> b;
	if (b.size() == 2)
	{
		a = b;
	}
	else
	{
		a += b[0];
		ll i;

		for (i = 1; i < b.size(); i += 2)
		{
			a += b[i];
		}
		if (i == b.size())
		{
			a += b[b.size() - 1];
		}
	}
	cout << a << "\n";
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