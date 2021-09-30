#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

bool isPossible(int limit, int countS, vector<int> &arr)
{
	int curr = 1, pages = 0;
	for (int x : arr)
	{
		if (x > limit)
		{
			return false;
		}

		if (pages + x > limit)
		{
			curr++;
			pages = x;
		}
		else
		{
			pages += x;
		}

		if (curr > countS)
		{
			return false;
		}
	}

	return true;
}


int allocateBooks(vector<int> arr, int n, int m) {
	// Write your code here.
	if (n < m)
	{
		return -1;
	}

	int l = INT_MAX, r = 0;
	for (int x : arr)
	{
		l = min(l, x);
		r += x;
	}

	int ans = -1;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (isPossible(mid, m, arr))
		{
			ans = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}

	return ans;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> arr(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << allocateBooks(arr, n, m) << "\n";
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
	t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}