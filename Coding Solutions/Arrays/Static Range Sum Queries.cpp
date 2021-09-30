#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, q, curr_sum = 0;
	cin >> n >> q;
	vector<ll> v(n, 0);
	for (ll i = 0; i < n; i++)
	{
		cin >> v[i];
		curr_sum += v[i];
		v[i] = curr_sum;
	}

	while (q--)
	{
		ll a, b;
		cin >> a >> b;
		cout << v[b - 1] - (a >= 2 ? v[a - 2] : 0) << "\n";
	}
}

int main() {
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