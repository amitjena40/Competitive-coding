#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, m;
	cin >> n >> m;
	ll a[n][m], rows[n], cols[m];
	memset(rows, 0, sizeof(rows));
	memset(cols, 0, sizeof(cols));
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1)
			{
				rows[i] = 1;
				cols[j] = 1;
			}
		}
	}

	ll i = 0, j = 0, step = 0;
	while (i != n && j != m)
	{

		if (rows[i] == 1 && cols[j] == 1)
		{
			i++;
			j++;
		}
		else if (rows[i] == 1)
		{
			i++;
		}
		else if (cols[j] == 1)
		{
			j++;
		}
		else
		{
			a[i][j] = 1;
			rows[i] = 1;
			cols[j] = 1;
			step++;
			i++;
			j++;
		}

	}

	if (step % 2 == 0)
	{
		cout << "Vivek\n";
	}
	else
	{
		cout << "Ashish\n";
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
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}