#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

bool cmp(pair<ll, ll> p1, pair<ll, ll> p2)
{
	return p1.first < p2.first;
}

void solve()
{
	ll n;
	cin >> n;
	vector<pair<ll, ll>> v;
	for (ll i = 0; i < n; i++)
	{
		ll x, y;
		cin >> x >> y;
		v.PB(make_pair(x, y));
	}

	sort(v.begin(), v.end(), cmp);
	pair<ll, ll> curr;
	vector<pair<ll , ll>> ans;
	curr = v[0];
	for (ll i = 1; i < n; i++)
	{
		if (v[i].first <= curr.second)
		{
			curr.second = max(v[i].second, curr.second);
		}
		else
		{
			ans.PB(curr);
			curr = v[i];
		}
	}

	ans.PB(curr);

	for (ll i = 0 ; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second << " ";
	}
	cout << "\n";
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