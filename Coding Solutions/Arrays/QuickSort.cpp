#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

ll partition(ll a[], ll start, ll end)
{
	ll pivot = a[end];
	ll pIndex = start;

	for (ll i = start; i < end; i++)
	{
		if (a[i] <= pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}

	swap(a[pIndex], a[end]);
	return pIndex;
}

ll randomPartition(ll arr[], ll l, ll r)
{
	ll n = r - l + 1;
	ll pivot = rand() % n;
	swap(arr[l + pivot], arr[r]);
	return partition(arr, l, r);
}


void QuickSort(ll a[], ll start, ll end)
{
	if (start >= end)return;
	ll pIndex = randomPartition(a, start, end);
	QuickSort(a, start, pIndex - 1);
	QuickSort(a, pIndex + 1, end);
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

	QuickSort(a, 0, n - 1);

	for (ll i = 0; i < n; i++)
	{
		cout << a[i] << " ";
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
	t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}