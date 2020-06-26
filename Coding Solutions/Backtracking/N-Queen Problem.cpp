#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

ll board[10][10];

bool isPossible(ll row, ll col, ll n)
{
	for (ll i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (board[i][j] == 1)
		{
			return false;
		}
	}

	for (ll i = row - 1; i >= 0; i--)
	{
		if (board[i][col] == 1)
		{
			return false;
		}
	}

	for (ll i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
	{
		if (board[i][j] == 1)
		{
			return false;
		}
	}

	return true;
}

void nQueens(ll row, ll n, vector<vector<ll>> &ans, vector<ll> probAns)
{
	if (row == n)
	{
		ans.PB(probAns);
		return;
	}

	for (ll j = 0; j < n; j++)
	{
		if (isPossible(row, j, n))
		{
			board[row][j] = 1;
			probAns.PB(j + 1);
			nQueens(row + 1, n, ans, probAns);
			probAns.pop_back();
			board[row][j]  = 0;
		}
	}
}

void solve()
{
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			board[i][j] = 0;
		}
	}

	vector<vector<ll>> ans;
	vector<ll> probAns;
	nQueens(0, n, ans, probAns);
	if (ans.empty())
	{
		cout << "-1\n";
	}
	else
	{
		for (ll i = 0; i < ans.size(); i++)
		{
			cout << "[";
			for (ll j = 0; j < ans[i].size(); j++)
			{
				cout << ans[i][j] << " ";
			}
			cout << "] ";
		}
		cout << "\n";
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