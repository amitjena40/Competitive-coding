#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll a, b;
	cin >> a >> b;
	if (b < a)
	{
		swap(a, b);
	}

	if (a == 0 || b == 0)
	{
		cout << 0 << "\n";
	}
	else if (2 * a <= b)
	{
		cout << a << "\n";
	}
	else
	{
		cout << (a + b) / 3 << "\n";
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