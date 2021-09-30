#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

ll fn(ll p, vector<ll> &ans, vector<vector<ll>> &child)
{
	ans[p] = 0;
	for (auto x : child[p])
	{
		ans[p] += 1 + fn(x, ans, child);
	}

	return ans[p];
}

void solve()
{
	ll n;
	cin >> n;
	vector<vector<ll>> child(n + 1);

	for (ll i = 2; i <= n; i++)
	{
		ll p;
		cin >> p;
		child[p].push_back(i);
	}

	vector<ll> ans(n + 1);
	fn(1, ans, child);
	for (ll i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
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