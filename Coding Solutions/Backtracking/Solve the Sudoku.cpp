#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

ll mat[9][9];

bool isPossible(ll row, ll col, ll val)
{
	for (ll i = 0; i < 9; i++)
	{
		if (mat[i][col] == val)
		{
			return false;
		}
	}

	for (ll j = 0; j < 9; j++)
	{
		if (mat[row][j] == val)
		{
			return false;
		}
	}

	for (ll i = row - row % 3; i <= (row - row % 3 + 2); i++)
	{
		for (ll j = col - col % 3; j <= (col - col % 3 + 2); j++)
		{
			if (mat[i][j] == val)
			{
				return false;
			}
		}
	}

	return true;
}

bool solveSudoku(ll idx, vector<pair<ll, ll>> &blank)
{
	if (idx == blank.size())
	{
		return true;
	}

	for (ll i = 1; i <= 9; i++)
	{
		if (isPossible(blank[idx].first, blank[idx].second, i))
		{
			mat[blank[idx].first][blank[idx].second] = i;
			if (solveSudoku(idx + 1, blank))
			{
				return true;
			}

			mat[blank[idx].first][blank[idx].second] = 0;
		}
	}

	return false;
}

void solve()
{
	vector<pair<ll, ll>> blank;
	for (ll i = 0; i < 9; i++)
	{
		for (ll j = 0; j < 9; j++)
		{
			cin >> mat[i][j];
			if (mat[i][j] == 0)
			{
				blank.PB(make_pair(i, j));
			}
		}
	}

	bool ans = solveSudoku(0, blank);
	if (ans)
	{
		for (ll i = 0; i < 9; i++)
		{
			for (ll j = 0; j < 9; j++)
			{
				cout << mat[i][j] << " ";
			}
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