#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

ll getTime(string s)
{
	ll n = s.size(), num = 0;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		num += (s[i] - '0') * pow(10, n - 1 - i);
	}
	return num;
}

void solve()
{
	ll n;
	cin >> n;
	ll arr[n], dep[n];
	string time;
	for (ll i = 0; i < n; ++i)
	{
		cin >> time;
		arr[i] = getTime(time);
	}

	for (ll i = 0; i < n; ++i)
	{
		cin >> time;
		dep[i] = getTime(time);
	}

	sort(arr, arr + n);
	sort(dep, dep + n);

	ll i = 0, j = 0, plat = 0, ans = INT_MIN;
	while (i < n && j < n)
	{
		if (arr[i] <= dep[j])
		{
			plat++;
			ans = max(ans, plat);
			i++;
		}
		else
		{
			plat--;
			j++;
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