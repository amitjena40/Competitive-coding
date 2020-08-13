#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll a[n], count = 0, mem;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cin >> mem;

	unordered_set<ll> s;
	unordered_map<ll, ll> m;
	for (ll i = 0; i < n; i++)
	{
		if (s.size() < mem)
		{
			if (s.find(a[i]) == s.end())
			{
				s.insert(a[i]);
				count++;
			}
		}
		else
		{
			if (s.find(a[i]) == s.end())
			{
				ll min_id = INT_MAX;
				for (auto it = s.begin(); it != s.end(); it++)
				{
					if (m[*it] < min_id)
					{
						min_id = m[*it];
					}
				}
				s.erase(a[min_id]);
				s.insert(a[i]);
				count++;
			}

		}
		m[a[i]] = i;
	}

	cout << count << "\n";
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