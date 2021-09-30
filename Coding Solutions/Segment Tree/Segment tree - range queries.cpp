#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

ll arr[2 * 100000], seg[8 * 100000];

void build(ll idx, ll lo, ll hi) {
	if (lo == hi) {
		seg[idx] = arr[lo];
		return;
	}
	ll mid = lo + (hi - lo) / 2;
	build(2 * idx + 1, lo, mid);
	build(2 * idx + 2, mid + 1, hi);
	seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
}

ll query(ll idx, ll lo, ll hi, ll l, ll r) {
	if (lo >= l && hi <= r) {
		return seg[idx];
	}
	else if (hi < l || lo > r) {
		return INT_MAX;
	}
	else {
		ll mid = lo + (hi - lo) / 2;
		ll x = query(2 * idx + 1, lo, mid, l, r);
		ll y = query(2 * idx + 2, mid + 1, hi, l, r);
		return min(x, y);
	}
}

void solve()
{
	ll n, q;
	cin >> n >> q;
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}

	build(0, 0, n - 1);
	while (q--) {
		ll a, b;
		cin >> a >> b;
		cout << query(0, 0, n - 1, a - 1, b - 1) << "\n";
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
	t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}