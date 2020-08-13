#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, k;
	cin >> n >> k;
	vector<ll> alice, bob, both;
	for (ll i = 0; i < n; i++)
	{
		ll t, a, b;
		cin >> t >> a >> b;
		if (a == 1 and b == 1)
		{
			both.PB(t);
		}
		else if (a == 1)
		{
			alice.PB(t);
		}
		else if (b == 1)
		{
			bob.PB(t);
		}
	}

	sort(alice.begin(), alice.end());
	sort(bob.begin(), bob.end());
	for (ll i = 0; i < min(alice.size(), bob.size()); i++)
	{
		both.PB(alice[i] + bob[i]);
	}
	sort(both.begin(), both.end());
	if (both.size() < k)
	{
		cout << "-1";
	}
	else
	{
		ll sum = 0;
		for (ll i = 0; i < k; i++)
		{
			sum += both[i];
		}
		cout << sum;
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
	solve();
	return 0;
}