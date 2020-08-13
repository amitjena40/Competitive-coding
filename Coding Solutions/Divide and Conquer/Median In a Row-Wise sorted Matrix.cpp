#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	int r, c;
	cin >> r >> c;
	int m[r][c];
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> m[i][j];
		}
	}

	int min = INT_MAX, max = INT_MIN;
	for (int i = 0; i < r; i++)
	{
		if (m[i][0] < min)
			min = m[i][0];

		if (m[i][c - 1] > max)
			max = m[i][c - 1];
	}

	int desired = (r * c + 1) / 2;
	while (min < max)
	{
		int mid = min + (max - min) / 2;
		int place = 0;

		for (int i = 0; i < r; ++i)
		{
			place += upper_bound(m[i], m[i] + c, mid) - m[i];
		}
		if (place < desired)
			min = mid + 1;
		else
			max = mid;

		//cout << "Max: " << max << " Min: " << min << "\n";
	}

	cout << min << "\n";
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