#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void merge(ll a[], ll n, ll L[], ll sizeL, ll R[], ll sizeR, ll &invcnt)
{
	ll i = 0, j = 0, k = 0;
	while (i < sizeL && j < sizeR)
	{
		if (L[i] <= R[j])
		{
			a[k++] = L[i++];
		}
		else
		{
			invcnt += sizeL - i;
			a[k++] = R[j++];
		}
	}

	while (i < sizeL)
	{
		a[k++] = L[i++];
	}

	while (j < sizeR)
	{
		a[k++] = R[j++];
	}
}

void mergeSort(ll a[], ll n, ll &invcnt)
{
	if (n < 2)
	{
		return;
	}

	ll mid = n / 2;
	ll *L = new ll[mid];
	ll *R = new ll[n - mid];
	for (ll i = 0; i < mid; i++)
	{
		L[i] = a[i];
	}

	for (ll i = mid; i < n; i++)
	{
		R[i - mid] = a[i];
	}

	mergeSort(L, mid, invcnt);
	mergeSort(R, n - mid, invcnt);
	merge(a, n, L, mid, R, n - mid, invcnt);
	delete(L);
	delete(R);
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

	ll invcnt = 0;
	mergeSort(a, n, invcnt);
	cout << invcnt << "\n";
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