#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	string str, pat;
	cin >> str >> pat;

	ll lps[pat.size()], index = 0;
	lps[0] = 0;
	for (ll i = 1; i < pat.size();)
	{
		if (pat[i] == pat[index])
		{
			lps[i] = index + 1;
			index++;
			i++;
		}
		else
		{
			if (index != 0)
			{
				index = lps[index - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}

	ll i = 0, j = 0, flag = 0;
	while (i < str.size() && j < pat.size())
	{
		if (str[i] == pat[j])
		{
			i++;
			j++;
		}
		else
		{
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
			{
				i++;
			}
		}

		if (j == pat.size())
		{
			cout << "Match found at pos: " << i - pat.size() + 1 << "\n";
			j = lps[j - 1];
			flag = 1;
		}
	}

	if (flag == 0)
	{
		cout << "Match not found!\n";
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
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}