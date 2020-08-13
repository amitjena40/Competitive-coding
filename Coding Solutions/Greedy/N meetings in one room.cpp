#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

struct meets
{
	ll start, end, no;
};

bool cmp(meets meet1, meets meet2)
{
	return meet1.end < meet2.end;
}

void solve()
{
	ll n;
	cin >> n;
	meets meet[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> meet[i].start;
		meet[i].no = i + 1;
	}

	for (ll i = 0; i < n; i++)
	{
		cin >> meet[i].end;
	}

	sort(meet, meet + n, cmp);
	cout << meet[0].no << " ";
	ll latest = meet[0].end;
	for (ll i = 1; i < n; i++)
	{
		if (meet[i].start >= latest)
		{
			cout << meet[i].no << " ";
			latest = meet[i].end;
		}
	}
	cout << "\n";
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