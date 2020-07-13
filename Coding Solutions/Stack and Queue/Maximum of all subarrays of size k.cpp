#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, k;
	cin >> n >> k;
	ll a[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	deque<ll> q;
	ll i;
	for (i = 0; i < k; i++)
	{
		while (!q.empty() && a[i] > a[q.back()])
		{
			q.pop_back();
		}
		q.push_back(i);
	}

	for (; i < n; i++)
	{
		cout << a[q.front()] << " ";
		while (!q.empty() && q.front() <= (i - k))
		{
			q.pop_front();
		}

		while (!q.empty() && a[i] >= a[q.back()])
		{
			q.pop_back();
		}

		q.push_back(i);
	}

	cout << a[q.front()] << "\n";
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