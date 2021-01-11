#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll m, n;
	cin >> m >> n;
	ll a[m], b[n];
	for (ll i = 0; i < m; i++)
	{
		cin >> a[i];
	}

	for (ll i = 0; i < n; i++)
	{
		cin >> b[i];
	}

	ll i = 0, j = 0;
	unordered_set<ll> seq;
	while (i < m && j < n)
	{
		if (a[i] < b[j])
		{
			seq.insert(a[i]);
			i++;
		}
		else if (a[i] > b[j])
		{
			seq.insert(b[j]);
			j++;
		}
		else
		{
			seq.insert(a[i]);
			i++;
			j++;
		}
	}

	while (i < m)
	{
		seq.insert(a[i]);
		i++;
	}

	while (j < n)
	{
		seq.insert(b[j]);
		j++;
	}

	cout << seq.size() << "\n";
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
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}