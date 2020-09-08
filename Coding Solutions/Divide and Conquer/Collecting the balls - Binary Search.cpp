#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

bool check(ll k, ll n)
{
	ll sum = 0, num = n;
	while (n > 0)
	{
		sum += min(n, k);
		n -= k;
		n -= n / 10;
	}

	return 2 * sum >= num;
}

void solve()
{
	ll n;
	cin >> n;

	ll lo = 1, hi = n, ans;
	while (lo <= hi)
	{
		ll mid = lo + (hi - lo) / 2;
		if (check(mid, n))
		{
			ans = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}

	cout << ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}