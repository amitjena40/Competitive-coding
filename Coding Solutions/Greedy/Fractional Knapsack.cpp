#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

struct items
{
	float val, wt;
};

bool cmp(items it1, items it2)
{
	return (it1.val / it1.wt) > (it2.val / it2.wt);
}

void solve()
{
	ll n;
	float w;
	cin >> n >> w;
	items item[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> item[i].val >> item[i].wt;
	}

	sort(item, item + n, cmp);
	float curr_val = 0;
	for (ll i = 0; i < n; i++)
	{
		if (item[i].wt <= w)
		{
			curr_val += item[i].val;
			w -= item[i].wt;
		}
		else
		{
			curr_val += (w / item[i].wt) * item[i].val;
			break;
		}
	}

	cout << fixed << setprecision(2) << curr_val << "\n";
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