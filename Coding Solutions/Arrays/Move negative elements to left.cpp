#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void two_pointer(ll a[], ll n)
{
	ll left = 0, right = n - 1;

	while (left <= right)
	{
		if (a[left] < 0 && a[right] < 0)
		{
			left++;
		}
		else if (a[left] >= 0 && a[right] < 0)
		{
			swap(a[left], a[right]);
			left++;
		}
		else if (a[left] >= 0 && a[right] >= 0)
		{
			right--;
		}
		else
		{
			left++;
			right--;
		}
	}

	for (ll i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

void quicksort(ll a[], ll n)
{
	ll j = 0;
	for (ll i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			if (i != j)
			{
				swap(a[i], a[j]);
			}
			j++;
		}
	}

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
		ll n;
		cin >> n;
		ll a[n];
		for (ll i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		//two_pointer(a, n);
		quicksort(a, n);
	}
	return 0;
}