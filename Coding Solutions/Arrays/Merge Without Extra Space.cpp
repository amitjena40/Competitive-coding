#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

ll nextGap(ll gap)
{
	if (gap <= 1)
	{
		return 0;
	}
	else
	{
		return (gap / 2) + gap % 2;
	}
}

void solve()
{
	ll x, y;
	cin >> x >> y;
	ll p[x], q[y];
	for (ll i = 0; i < x; i++)
	{
		cin >> p[i];
	}

	for (ll i = 0; i < y; i++)
	{
		cin >> q[i];
	}

	ll i, j, gap = x + y;
	for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
	{
		for (i = 0; i + gap < x; i++)
		{
			if (p[i] > p[i + gap])
			{
				swap(p[i], p[i + gap]);
			}
		}

		for (j = gap > x ? gap - x : 0; i < x && j < y; i++, j++)
		{
			if (p[i] > q[j])
			{
				swap(p[i], q[j]);
			}
		}

		if (j < y)
		{
			for (j = 0; j + gap < y; j++)
			{
				if (q[j] > q[j + gap])
				{
					swap(q[j], q[j + gap]);
				}
			}
		}
	}

	for (ll i = 0; i < x; i++)
	{
		cout << p[i] << " ";
	}

	for (ll i = 0; i < y; i++)
	{
		cout << q[i] << " ";
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