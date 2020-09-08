#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

ll merge(ll a[], ll n, ll left[], ll n1, ll right[], ll n2)
{
	ll i = 0, j = 0, k = 0;
	ll sum = 0;
	while (i < n1 && j < n2)
	{
		if (left[i] < right[j])
		{
			sum += left[i] * (n2 - j);
			a[k++] = left[i++];
		}
		else
		{
			a[k++] = right[j++];
		}
	}

	while (i < n1)
	{
		a[k++] = left[i++];
	}

	while (j < n2)
	{
		a[k++] = right[j++];
	}

	return sum;
}

ll mSort(ll a[], ll n)
{
	if (n < 2)
	{
		return 0;
	}

	ll mid = n / 2;
	ll *left = new ll[mid];
	ll *right = new ll[n - mid];

	for (ll i = 0; i < mid; i++)
	{
		left[i] = a[i];
	}

	for (ll i = mid; i < n; i++)
	{
		right[i - mid] = a[i];
	}

	ll ans = mSort(left, mid) + mSort(right, n - mid) + merge(a, n, left, mid, right, n - mid);
	delete(left);
	delete(right);
	return ans;
}

void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	ll ans = mSort(a, n);
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