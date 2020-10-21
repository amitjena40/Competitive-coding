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
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	stack<ll> s;
	s.push(0);

	cout << "1 ";
	for (ll i = 1; i < n; i++)
	{
		while (!s.empty() and a[i] >= a[s.top()])
		{
			s.pop();
		}

		if (s.empty())
		{
			cout << i + 1 << " ";
		}
		else
		{
			cout << i - s.top() << " ";
		}

		s.push(i);
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