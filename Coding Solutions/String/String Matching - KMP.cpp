#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	string str, ptr;
	cin >> str >> ptr;

	vector<ll> lps(ptr.size(), 0);
	ll index = 0;
	for (ll i = 1; i < ptr.size();)
	{
		if (ptr[i] == ptr[index])
		{
			lps[i] = index + 1;
			index++;
			i++;
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

	ll i = 0, j = 0, ans = 0;
	while (i < str.size() && j < ptr.size())
	{
		if (str[i] == ptr[j])
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

		if (j == ptr.size())
		{
			ans++;
			j = lps[j - 1];
		}
	}

	cout << ans;
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