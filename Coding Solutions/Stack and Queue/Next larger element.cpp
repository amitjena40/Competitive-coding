#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin >> a[i];
	}

	stack<ll> s;
	s.push(a[0]);
	unordered_map<ll, ll> m;
	for (int i = 1; i < n; ++i)
	{
		while (!s.empty() and a[i] > s.top())
		{
			m[s.top()] = a[i];
			s.pop();
		}
		s.push(a[i]);
	}

	for (ll i = 0; i < n; i++)
	{
		if (m[a[i]] == 0)
		{
			cout << "-1 ";
		}
		else
		{
			cout << m[a[i]] << " ";
		}
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