#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll a[n], nneg = 0, nzero = 0, npos = 0, max_neg = INT_MIN, ans = 1;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] < 0)
		{
			nneg++;
			if (a[i] > max_neg)
			{
				max_neg = a[i];
			}
			ans *= a[i];
		}
		else if (a[i] == 0)
		{
			nzero++;
		}
		else
		{
			npos++;
			ans *= a[i];
		}
	}

	if (nneg % 2 != 0)
	{
		ans /= max_neg;
	}
	if (npos == 0 && nzero > 0)
	{
		ans = 0;
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