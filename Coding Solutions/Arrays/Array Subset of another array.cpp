#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n1, n2;
	cin >> n1 >> n2;
	ll a1[n1], a2[n2];
	for (ll i = 0; i < n1; i++)
	{
		cin >> a1[i];
	}

	for (ll i = 0; i < n2; i++)
	{
		cin >> a2[i];
	}

	ll lps[n2];
	ll index = 0;
	lps[0] = 0;

	for (ll i = 1; i < n2;)
	{
		if (a2[i] == a2[index])
		{
			lps[1] = index + 1;
			i++;
			index++;
		}
		else if (index != 0)
		{
			index = lps[index - 1];
		}
		else
		{
			lps[i] = 0;
			i++;
		}
	}

	ll i = 0, j = 0;
	while (i < n1 && j < n2)
	{
		if (a1[i] == a2[j])
		{
			i++;
			j++;
		}
		else if (j != 0)
		{
			j = lps[j - 1];
		}
		else
		{
			i++;
		}

		if (j == n2)
		{
			cout << "Yes\n";
			return;
		}
	}

	cout << "No\n";
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
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}