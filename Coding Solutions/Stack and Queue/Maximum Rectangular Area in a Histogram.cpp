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
	ll i, ans = 0;
	s.push(0);
	for (i = 1; i < n; i++)
	{
		if (a[i] > a[s.top()])
		{
			s.push(i);
		}
		else
		{
			while (!s.empty() && a[i] < a[s.top()])
			{
				ll ht = s.top(), area;
				s.pop();
				if (s.empty())
				{
					area = a[ht] * i;
				}
				else
				{
					area = a[ht] * (i - s.top() - 1);
				}

				ans = max(ans, area);
			}
			s.push(i);
		}
	}

	while (!s.empty())
	{
		ll ht = s.top(), area;
		s.pop();
		if (s.empty())
		{
			area = a[ht] * i;
		}
		else
		{
			area = a[ht] * (i - s.top() - 1);
		}

		ans = max(ans, area);
	}

	cout << ans << "\n";
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