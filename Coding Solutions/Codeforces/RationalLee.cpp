#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

//Editorial Method
void solve1()
{
	ll n, k;
	cin >> n >> k;
	ll a[n], w[k];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (ll i = 0; i < k; i++)
	{
		cin >> w[i];
	}

	sort(a, a + n);
	sort(w, w + k);

	ll ans = 0, start = 0, end = n - 1, p = 0;
	for (ll i = 0; i < k; i++)
	{
		if (w[i] == 1)
		{
			ans += 2 * a[end];
			p++;
			end--;
		}
		else
		{
			break;
		}
	}

	for (ll i = k - 1; i >= p; i--)
	{
		ans += a[end] + a[start];
		end--;
		start++;
		w[i] -= 2;
		while (w[i] > 0)
		{
			start++;
			w[i]--;
		}
	}

	cout << ans << "\n";
}

//Another Method
void solve2()
{
	ll n, k;
	cin >> n >> k;
	ll a[n], w[k];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (ll i = 0; i < k; i++)
	{
		cin >> w[i];
	}

	sort(a, a + n);
	sort(w, w + k);

	ll ans = 0, ptr = n - k, largest = n - 1;
	for (ll i = 0; i < k; i++)
	{
		ans += a[largest];
		if (w[i] == 1)
		{
			ans += a[largest];
		}
		else
		{
			for (ll j = 0; j < (w[i] - 1); j++)
			{
				ptr--;
			}
			ans += a[ptr];
		}
		largest--;
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
		solve2();
	}
	return 0;
}