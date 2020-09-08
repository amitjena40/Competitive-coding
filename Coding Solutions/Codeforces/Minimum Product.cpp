#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll a, b, x, y, n;
	cin >> a >> b >> x >> y >> n;
	ll op1, op2;
	ll a1 = a, b1 = b;

	if (n > (a - x))
	{
		a = x;
		b = max(b - (n - (a1 - x)), y);
	}
	else
	{
		a -= n;
	}

	op1 = a * b;

	ll b2 = b1;
	if (n > (b1 - y))
	{
		b1 = y;
		a1 = max(a1 - (n - (b2 - y)), x);
	}
	else
	{
		b1 -= n;
	}

	op2 = a1 * b1;

	//cout << a << " " << a1 << "!" << b << " " << b1 << "!";
	cout << min(op1, op2) << "\n";
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