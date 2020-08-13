#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll a[100001], cnt[100001];
	memset(a, 0, sizeof(a));
	memset(cnt, 0, sizeof(cnt));
	for (ll i = 0; i < n; i++)
	{
		ll item;
		cin >> item;
		a[item]++;
		cnt[a[item]]++;
	}

	ll q;
	cin >> q;
	while (q--)
	{
		char ch;
		ll x;
		cin >> ch >> x;
		if (ch == '+')
		{
			a[x]++;
			cnt[a[x]]++;
		}
		else
		{
			cnt[a[x]]--;
			a[x]--;
		}

		if (cnt[8] > 0 || cnt[4] >= 2 || (cnt[6] > 0 && cnt[2] >= 2) || (cnt[4] > 0 && cnt[2] >= 3))
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
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
	/*ll t;
	cin >> t;
	while (t--)
	{
	    solve();
	}*/
	solve();
	return 0;
}