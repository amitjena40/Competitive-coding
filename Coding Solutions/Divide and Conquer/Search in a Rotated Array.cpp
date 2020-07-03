#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n, k;
	cin >> n;
	ll A[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	cin >> k;

	ll mid, start = 0, end = n - 1;
	while (start < end)
	{
		mid = start + (end - start) / 2;
		if (A[mid] > A[end])
		{
			start = mid + 1;
		}
		else
		{
			end = mid;
		}
	}

	ll mid1, start1 = 0, end1 = end - 1, mid2, start2 = end, end2 = n - 1;
	ll ans = -1;

	while (start1 <= end1)
	{
		mid1 = start1 + (end1 - start1) / 2;
		if (A[mid1] == k)
		{
			ans = mid1;
			break;
		}
		else if (A[mid1] < k)
		{
			start1 = mid1 + 1;
		}
		else
		{
			end1 = mid1 - 1;
		}
	}

	while (start2 <= end2)
	{
		mid2 = start2 + (end2 - start2) / 2;
		if (A[mid2] == k)
		{
			ans = mid2;
			break;
		}
		else if (A[mid2] < k)
		{
			start2 = mid2 + 1;
		}
		else
		{
			end2 = mid2 - 1;
		}
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