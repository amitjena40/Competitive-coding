#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll A[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	ll low = 0, high = n - 1, mid;
	while (low < high)
	{
		ll mid = (low + high) / 2;
		if (mid % 2 == 0)
		{
			if (A[mid] == A[mid + 1])
			{
				low = mid + 2;
			}
			else
			{
				high = mid;
			}
		}
		else
		{
			if (A[mid] == A[mid - 1])
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
	}

	cout << A[low] << "\n";
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